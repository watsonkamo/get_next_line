/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emma <emma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 04:37:21 by emma              #+#    #+#             */
/*   Updated: 2024/02/11 04:37:22 by emma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// __attribute((destructor)) static void destructor()
// {
//     system("leaks -q a.out");
// }


char *get_next_line(int fd)
{
    char *list; //改行までの文字列を格納
    static char *save; //ここには改行後の文字列が格納されていく
    if (fd < 0 || BUFFER_SIZE <= 0 )
        return (0);
    save = ft_read(fd, save);//文字列全体を読み込む＝１回目は全部、２回目以降は＼n以降の文章を読む＝static変数で保存されている
    if (save == NULL)
        return (NULL);
    list = ft_outputline(save);//＼nまでの表示したい文字列をlistに格納=＼nを探し、＼nまでの文字列をlistに格納
    if (list == NULL)
        return (NULL);
    save = ft_leftover(save);//＼nより後ろの残りの文字列をsaveに格納=\nを見つけて、\nより後ろの文字列をsaveに格納
    if (save == NULL && list[0] == '\0')//saveがNULLで、listが空文字列の場合、listをfreeしてNULLを返す
    {
        free(list);
        return (NULL);
    }
    return (list);
}

char *ft_read(int fd, char *save)
{
    char *tmp;//読み込んだ文字列を一時的に格納するための変数
    int read_rtn;//readの戻り値格納 0:ファイルの終わり  -1:エラー  1:読み込み成功

    tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (tmp == NULL)
        return (NULL);
    read_rtn = 1;
    while (!ft_strchr(save, '\n') && read_rtn != 0)
    {
        read_rtn = read(fd, tmp, BUFFER_SIZE);
        if (read_rtn == -1)
        {
            free(tmp);
            return (NULL);
        }
        tmp[read_rtn] = '\0';
        // printf("tmp : [%s]\n", tmp);
        if (save == NULL)
            save = ft_strdup(tmp);
        else
            save = ft_strjoin(save, tmp);
        // save = ft_strdup(tmp);
        // printf("ft_read save : [%s]\n", save);
    }
    free(tmp);
    return (save);
}

char *ft_outputline(char *save)
{
    int i;
    char *rtn;

    i = 0;
    if (save == NULL)
        return (NULL);
    while (save[i] && save[i] != '\n')
        i++;
    rtn = (char *)malloc(sizeof(char) * (i + 2));//最後の＼nと終端文字を含めるために+2
    if (rtn == NULL)
        return (NULL);
    i = 0;
    while (save[i] && save[i] != '\n')
    {
        rtn[i] = save[i];
        i++;
    }
    if (save[i] == '\n')
        rtn[i++] = '\n';
    rtn[i] = '\0';
    return (rtn);
}

char *ft_leftover(char *save)
{
    int i;
    int j;
    char *rtn;

    i = 0;
    j = 0;
    if (save == NULL)
        return (NULL);
    while (save[i] && save[i] != '\n')
        i++;
    if (save[i] == '\0')
    {
        free(save);
        return (NULL);
    }
    rtn = (char *)malloc(ft_strlen(save) - i + 1);//＼nより後ろの文字列を格納するために、saveの長さから＼nまでの長さを引いて+1.終端文字を含めるため
    if (rtn == NULL)
        return (NULL);
    i++;
    while (save[i])
    {
        rtn[j] = save[i];
        i++;
        j++;
    }
    rtn[j] = '\0';
    free(save);
    return (rtn);
}

// #include <stdio.h>
// #include <fcntl.h>
// int main(void)
// {
//     int fd = open("text.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("open");
//         return (1);
//     }
//     char *line;
//     printf("fd:%d\n", fd);
//     int i = 0;
//     while (1)
//     {
//         line = get_next_line(fd);
//         printf("[%d] : %s", i++, line);
//         if (line == NULL)
//             break;
//         free(line);
//     }
//     close(fd);
// }