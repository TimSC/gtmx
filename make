# Make gtmrunx
#
gcc -c gtmrunx.c -I$gtm_dist
gcc gtmrunx.o -o gtmrunx -L$gtm_dist -Wlgtmshr -Wlc -WR $gtm_dist/libgtmshr.so
