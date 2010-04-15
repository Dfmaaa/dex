#ifndef WINDOW_H
#define WINDOW_H

#include "buffer.h"

struct window {
	struct list_head node;
	struct list_head views;

	/* current view. always exists */
	struct view *view;

	/* Coordinates and size of editable area not including tabs,
	 * status line and command line.
	 */
	int x, y;
	int w, h;
};

extern struct window *window;
extern struct list_head windows;

static inline struct window *WINDOW(struct list_head *item)
{
	return container_of(item, struct window, node);
}

struct window *window_new(void);
struct view *window_add_buffer(struct buffer *b);
void view_delete(struct view *v);
void remove_view(void);
void set_view(struct view *v);
void next_buffer(void);
void prev_buffer(void);
void update_cursor_y(void);
void update_cursor_x(void);
void update_cursor(void);
void center_view_to_cursor(void);

static inline int get_scroll_margin(void)
{
	int max = (window->h - 1) / 2;

	if (options.scroll_margin > max)
		return max;
	return options.scroll_margin;
}

unsigned int count_nl(const char *buf, unsigned int size);

#endif
