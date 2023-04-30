#include "minishel.h"

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sbr;
	unsigned int	i;
	unsigned int	j;

	j = len;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		j = ft_strlen(s + start);
	sbr = (char *)malloc((j + 1) * sizeof(char));
	if (sbr == NULL)
		return (NULL);
	i = j;
	while (j--)
	{
		*sbr = s[start];
		start++;
		sbr++;
	}
	*sbr = '\0';
	return (sbr - i);
}

char	*ft_strchr(const char *str, int c)
{
	char	*s;
	char	ch;

	ch = (char)c;
	s = (char *)str;
	while (*s != ch)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return (s);
}

char	*ft_strtok(char *str, char *sep)
{
	int			len;
	char		*rslt;
	static char	*container;

	if (str)
		container = str;
	if (!container)
		return (NULL);
	while (*container && ft_strchr(sep, *container))
		container++;
	len = 0;
	while (container[len] && !ft_strchr(sep, container[len]))
		len++;
	if (!len)
		return (NULL);
	rslt = ft_substr(container, 0, len);
	container += len;
	if (*container && ft_strchr(sep, *container))
		container++;
	return (rslt);
}

char	*ft_strdup( const char *source )
{
	char	*ptr;
	int		len ;
	int		i;

	i = 0;
	while (source[i] != '\0')
		i++;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	len = i ;
	if (ptr == NULL)
		return (NULL);
	while (i)
	{
		*ptr++ = *source++;
		i--;
	}
	*ptr = '\0';
	return (ptr - len);
}

char	*ft_strndup(char *start, char *end)
{
	char	*ptr;
	int		len ;
	int i;

	len = i = ft_strlen(start) - ft_strlen(end);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i)
	{
		*ptr++ = *start++;
		i--;
	}
	*ptr = '\0';
	return (ptr - len);
}

int	ft_strcmp(char *s11, char *s22)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s2 = (unsigned char *)s22;
	s1 = (unsigned char *)s11;
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	int		s1_len;
	int		s2_len;

	if (!(s1) && !(s2))
		return (NULL);
	if (!s1)
	{
		newstr = ft_strdup(s2);
		return (newstr);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!newstr)
		return (NULL);
	while (*s1)
		*newstr++ = *s1++;
	if (!s2)
		return (newstr);
	while (*s2)
		*newstr++ = *s2++;
	*newstr = '\0';
	return (newstr - s1_len - s2_len);
}

char	*ft_strtrim(char const *s1)
{
	char			*trm;
	char			*set;
	char 			**tmp;
	unsigned int	l;
	int				i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	if (!ft_strchr(s1,'"'))
		set = "'";
	else if (!ft_strchr(s1,'\''))
		set = "\"";
	else if (ft_strchr(s1,'"') < ft_strchr(s1,'\'') )
		set = "\"";
	else
		set = "'";
	while (ft_strchr(set, s1[i]))
		i++;
	l = ft_strlen(s1);
	while (ft_strchr(set, s1[l]) && (l > 0))
		l--;
	trm = ft_substr(s1, i, (l - i) + 1);
	tmp = ft_split(trm,*set);
	i = 0;
	
	while ((tmp[i + 1]))
	{
		trm = ft_strjoin(tmp[i] ,tmp[i+1]);
		i++;
	}
	
	return (trm);
}