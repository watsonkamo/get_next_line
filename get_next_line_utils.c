/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emma <emma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 04:37:27 by emma              #+#    #+#             */
/*   Updated: 2024/02/11 04:37:28 by emma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    // if (s == NULL)
    //      return (0);
    while (s[i] != '\0')
        i++;
    return (i);
}

char *ft_strchr(const char *str, int c)//文字列strの中に文字cがあるかどうかを調べる=>あればその文字へのポインタを返す
{
    int i;

    i = 0;
    if (!str)
        return (0); // NULLポインタが渡された場合はNULLを返す
    c = (unsigned char)c;
    if (c == '\0')
        return (NULL); // 文字が見つからない場合、終端のNULL文字へのポインタを返す
    while (str[i] != '\0')
    {
        if (str[i] == c)
            return ((char *)&str[i]);
        i++;
    }
    return (NULL); // 文字が見つからない場合NULLを返す
}

char    *ft_strjoin(char *s1, char *s2)//文字列s1とs2を結合する
{
    char    *result;//結合した文字列を格納するためのポインタ
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (s1 == NULL || s2 == NULL)
        return (0);
    result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    // printf("%p file -> %s line ->%d\n", result, __FILE__, __LINE__);
    if (result == NULL)
        return (0);
    while (s1[i] != '\0')
    {
        result[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0')
    {
        result[i + j] = s2[j];
        j++;
    }
    result[i + j] = '\0';
    free(s1);
    return (result);
}

char	*ft_strdup(const char *src)//文字列srcのコピーを作成し、そのコピーへのポインタを返す
{
    char	*dest;
    int		i;

    dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
    //freeする関数の中で、mallocで確保したメモリをfreeする?
    // printf("%p file -> %s line ->%d\n", dest, __FILE__, __LINE__);
    if (dest == NULL)
        return (NULL);
    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    // printf("Hello!!!\n");
    return (dest);
}