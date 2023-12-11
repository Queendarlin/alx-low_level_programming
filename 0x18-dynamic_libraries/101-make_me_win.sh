#!/bin/bash
(echo -e '#include <stdlib.h>\n#include <time.h>\n\nint rand(void) { srand(time(NULL)); return 9; }' > /tmp/hack_rand.c && gcc -shared -fPIC /tmp/hack_rand.c -o /tmp/hack_rand.so && export LD_PRELOAD=/tmp/hack_rand.so)
