int bins(int x, int a[], int l, int r){
    int m = (l + (r - l) / 2);
    if (x == a[m]) { return m;}
        else if ( x == a[l]) { return l;}
    else if ( x == a[r]) { return r;}
    else if (x < a[m]) {return(bins(x, a, l, m));}
    else {return(bins(x, a, m, r));}
}
