# ft_printf

A recreation of the libc printf, with a few differences. As with all projects at 42, use of the system
library (libc) is heavily restricted. With the only calls we are allowed to use being:
write, free, malloc, open, and read.

Available flags:
  %s, %d, %i, %f, %x, %X, %o, %p
  
New Flags:
  %b - binary version of %x
  %v - reads and prints (or stores) a file, given name of file, or the file descriptor if alt fmt flag is used.
