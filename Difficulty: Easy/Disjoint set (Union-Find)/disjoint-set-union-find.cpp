/*Complete the functions below*/
int find(int par[], int x) {
    // add code here
    if(x == par[x]){
        return x;
    }
    
    return find(par, par[x]);
}

void unionSet(int par[], int x, int y) {
    // add code here.
    int x_parent = find(par, x);
    int y_parent = find(par, y);
    
    if(x_parent != y_parent){
        par[x_parent] = y_parent;
    }
}