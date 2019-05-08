

gdb ./src/redis-server
// 打上断点
(gdb) b setCommand
// 运行redis-server
(gdb) r ./redis.conf

Breakpoint 1, setCommand (c=0x7ffff6d4d8c0) at t_string.c:96
96      void setCommand(client *c) {
Missing separate debuginfos, use: debuginfo-install glibc-2.17-260.el7_6.4.x86_64
(gdb) bt
#0  setCommand (c=0x7ffff6d4d8c0) at t_string.c:96
#1  0x00000000004305d7 in call (c=c@entry=0x7ffff6d4d8c0, flags=flags@entry=15) at server.c:2433
#2  0x000000000043186f in processCommand (c=0x7ffff6d4d8c0) at server.c:2726
#3  0x00000000004403f5 in processInputBuffer (c=0x7ffff6d4d8c0) at networking.c:1452
#4  0x000000000042aaa0 in aeProcessEvents (eventLoop=eventLoop@entry=0x7ffff6c37050, flags=flags@entry=11) at ae.c:443
#5  0x000000000042ad6b in aeMain (eventLoop=0x7ffff6c37050) at ae.c:501
#6  0x0000000000427c1f in main (argc=<optimized out>, argv=0x7fffffffe518) at server.c:4194
