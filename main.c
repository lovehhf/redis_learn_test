#include <stdio.h>
#include <string.h>

typedef char *sds;

sds sdstrim(sds s, const char *cset) {
    char *start, *end, *sp, *ep;
    size_t len;

    // 设置和记录指针
    sp = start = s;
    ep = end = s+strlen(s)-1;

    printf("%p, %p\n", sp, ep);

    // 修剪, T = O(N^2)
    while(sp <= end && strchr(cset, *sp)) sp++;
    while(ep > start && strchr(cset, *ep)) ep--;

    printf("%p, %p\n", sp, ep);
    // 计算 trim 完毕之后剩余的字符串长度
    len = (sp > ep) ? 0 : ((ep-sp)+1);

    printf("%zu\n", len);

    return s;
}

int main(void) {
    sds a = "xxabxybayy";
    const char * b = "xy";
    sdstrim(a, b);
    printf("%s", (char *)a);
    return 0;
}