#ifndef UNICODE_H
#define UNICODE_H

static inline int u_is_unicode(unsigned int uch)
{
	return uch <= 0x10ffffU;
}

static inline int u_is_ctrl(unsigned int u)
{
	return u < 0x20 || u == 0x7f;
}

int u_is_unprintable(unsigned int u);
int u_is_special_whitespace(unsigned int u);
int u_char_width(unsigned int uch);

#endif
