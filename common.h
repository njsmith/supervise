#pragma once
#include <signal.h>
int try_function(int ret, const char *file, int line, const char *function, const char *program);

#define try_(x) \
    try_function(x, __FILE__, __LINE__, __FUNCTION__, #x )

/* Returns a signal set containing only the argument signal. */
sigset_t singleton_set(int signum);
/* Returns the currently blocked signal set. */
sigset_t get_blocked_signals(void);

/* Returns a signalfd which is readable when we get a SIGCHLD.
 * This function also blocks that signal. */
int get_childfd(void);

/* Marks SIGPIPE as ignored. */
void disable_sigpipe(void);
/* Makes the passed-in FD cloexec and nonblocking. */
void make_fd_cloexec_nonblock(int fd);
