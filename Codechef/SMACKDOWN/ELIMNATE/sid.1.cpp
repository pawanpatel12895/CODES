    #include <stdio.h>
     
    int main(int argc, char const *argv[])
    {
        long long t, r, c, m, k, j, tem, tem1;
        scanf("%lld", &t);
        while(t--) {
            scanf("%lld %lld", &r, &c);
            scanf("%lld %lld", &m, &k);
            if (m < k){ tem = m; m = k; k = tem; }
            scanf("%lld", &j);
            if (k < j && m > j) { tem = k; k = j; j = tem; }
            else if (m < j) {
                tem = m; tem1 = k; m = j;
                k = tem; j = tem1;
            }
            tem = r;
            if (r < c) { r = c; c = tem; }
            if (!(r && c)) { m || k || j ? puts("No") : puts("Yes"); }
            else if (r && m % r == 0){
                c -= m / r;
                if (r && k % r == 0){
                    c -= k / r;
                    if (j % r == 0){
                        c -= j / r;
                        !c ? puts("Yes") : puts("No");
                    }
                    else if (c && j % c == 0){
                        r -= j / c;
                        !r ? puts("Yes") : puts("No");
                    }
                    else if (!(r || c)) { j ? puts("No") : puts("Yes"); }
                    else
                        puts("No");
                }
                else if (c && k % c == 0){
                    r -= k / c;
                    if (r && j % r == 0){
                        c -= j / r;
                        !c ? puts("Yes") : puts("No");
                    }
                    else if (c && j % c == 0){
                        r -= j / c;
                        !r ? puts("Yes") : puts("No");
                    }
                    else if (!(r || c)) { j ? puts("No") : puts("Yes"); }
                    else
                        puts("No");   
                }
                else if (!(r || c)) { k || j ? puts("No") : puts("Yes"); }
                else
                    puts("No");
            }
            else if (c && m % c == 0){
                r -= m / c;
                if (r && k % r == 0){
                    c -= k / r;
                    if (r && j % r == 0){
                        c -= j / r;
                        !c ? puts("Yes") : puts("No");
                    }
                    else if (c && j % c == 0){
                        r -= j / c;
                        !r ? puts("Yes") : puts("No");
                    }
                    else if (!(r || c)) { j ? puts("No") : puts("Yes"); }
                    else
                        puts("No");
                }
                else if (c && k % c == 0){
                    r -= k / c;
                    if (r && j % r == 0){
                        c -= j / r;
                        !c ? puts("Yes") : puts("No");
                    }
                    else if (c && j % c == 0){
                        r -= j / c;
                        !r ? puts("Yes") : puts("No");
                    }
                    else if (!(r || c)) { j ? puts("No") : puts("Yes"); }
                    else
                        puts("No");   
                }
                else if (!(r || c)) { k || j ? puts("No") : puts("Yes"); }
                else
                    puts("No");
            }
            else{ puts("No"); }
        }
        return 0;
    } 
