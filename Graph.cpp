#include <iostream>
using namespace std;

template <class T>
class Edge
{
public:
    int start, end;
    T weight;
    Edge()
    {
        start = 0;
        end = 0;
        weight = 0;
    }
    Edge(int s, int e, T w)
    {
        start = s;
        end = e;
        weight = w;
    }
    bool operator>(Edge<T> l)
    {
        if (weight > l.weight)
            return true;
        else
            return false;
    }
};

template <class T>
class Heap
{
public:
    T *heap;
    int size;
    int maxsize;
    Heap(T *array, int num, int max)
    {
        heap = array;
        size = num;
        maxsize = max;
    }
    void build()
    {
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            shift(i);
        }
    }
    void shift(int left)
    {
        int i = left;
        int j = 2 * i + 1;
        T t = heap[i];
        while (j < size)
        {
            if ((j < size - 1) && (heap[j] > heap[j + 1]))
                j++;
            if (t > heap[j])
            {
                heap[i] = heap[j];
                i = j;
                j = 2 * j + 1;
            }
            else
                break;
        }
        heap[i] = t;
    }
    T remove()
    {
        if (size == 0)
        {
        }
        else
        {
            T t = heap[0];
            heap[0] = heap[size - 1];
            size--;
            if (size > 1)
                shift(0);
            return t;
        }
    }
    void insert(T t)
    {
        if (size == maxsize)
        {
            return;
        }
        else
        {
            heap[size] = t;
            size++;
            build();
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << heap[i] << ' ';
        }
        cout << endl;
    }
};

class UFSets
{
public:
    int n, *root, *next, *length;
    UFSets(int size)
    {
        n = size;
        root = new int[n];
        next = new int[n];
        length = new int[n];
        for (int i = 0; i < n; i++)
        {
            root[i] = next[i] = i;
            length[i] = 1;
        }
    }
    int find(int v) { return root[v]; }
    void un(int v, int u)
    {
        if (root[u] == root[v])
        {
            return;
        }
        if (length[root[v]] < length[root[u]])
        {
            int rt = root[v];
            length[root[u]] += length[rt];
            root[rt] = root[u];
            for (int j = next[rt]; j != rt; j = next[j])
                root[j] = root[u];
            swap(next[rt], next[root[u]]);
        }
        else
        {
            int rt = root[u];
            length[root[v]] += length[rt];
            root[rt] = root[v];
            for (int j = next[rt]; j != rt; j = next[j])
                root[j] = root[v];
            swap(next[rt], next[root[v]]);
        }
        return;
    }
};

template <class T>
class Graph
{
public:
    int vnum, ednum;
    int **map;
    Graph(int n)
    {
        int i, j;
        vnum = n;
        map = (int **)new int *[n];
        for (i = 0; i < n; i++)
        {
            map[i] = new int[n];
        }
        ednum = 0;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                cin >> map[i][j];
                if (map[i][j] != 0)
                    ednum++;
            }
    }
    Edge<T> fEdge(int v)
    {
        Edge<T> te;
        te.start = v;
        for (int i = 0; i < vnum; i++)
        {
            if (map[v][i] != 0)
            {
                te.end = i;
                te.weight = map[v][i];
                break;
            }
        }
        return te;
    }
    Edge<T> nEdge(Edge<T> one)
    {
        Edge<T> te;
        for (int i = one.end + 1; i < vnum; i++)
        {
            if (map[one.start][i] != 0)
            {
                te.end = i;
                te.weight = map[one.start][i];
                break;
            }
        }
        if (one.end + 1 >= vnum)
            return te;
        te.start = one.start;
        return te;
    }
    int isE(Edge<T> e)
    {
        return e.weight; //[e.start][e.end];
    }

    Edge<T> *prim(int s)
    {
        int i, j;
        Edge<T> *l, e;
        T *near;
        int *nei;
        int n = vnum;
        near = new T[n];
        nei = new int[n];
        l = new Edge<T>[n - 1];
        for (i = 0; i < n; i++)
        {
            nei[i] = s;
            near[i] = map[s][i];
        }
        nei[s] = -1;
        for (i = 1; i < n; i++)
        { //for(int k = 0;k < n;k++) cout<<near[k]<<' '<<nei[k]<<endl;
            T min = 10000;
            int v = -1;
            for (j = 0; j < n; j++)
            {
                if (nei[j] != -1 && near[j] != 0 && near[j] < min)
                {
                    min = near[j];
                    v = j;
                }
            }
            if (v >= 0)
            {
                Edge<T> te(nei[v], v, near[v]);
                l[i] = te;
                //cout<<'v'<<te.start+1<<" - "<<'v'<<te.end+1<<" = "<<te.weight<<endl;
                nei[v] = -1;
                for (j = 0; j < n; j++)
                {
                    if (map[v][j] != 0 && nei[j] != -1 && (map[v][j] < near[j] || near[j] == 0))
                    {
                        nei[j] = v;
                        near[j] = map[v][j];
                    }
                }
                /*for(e = fEdge(v);isE(e);e = nEdge(e)){
                    int u = e.end;cout<<u<<endl;
                    if(nei[u] != -1 && near[u] > e.weight){
                        nei[u] = v;
                        near[u] = e.weight;
                    }
                }*/
            }
        }
        return l;
    }
    Edge<T> *kruskal()
    {
        int n = vnum;
        UFSets set(n);
        Edge<T> *l = new Edge<T>[n - 1];
        Edge<T> *tem = new Edge<T>[ednum];
        Heap<Edge<T>> h(tem, 0, ednum);
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (map[i][j] != 0)
                {
                    Edge<T> t(i, j, map[i][j]);
                    h.insert(t);
                }
        Edge<T> edge;
        int edgen = 0;
        while (edgen < n - 1)
        {
            if (h.size != 0)
            {
                edge = h.remove();
                int v = edge.start;
                int u = edge.end;
                if (set.find(v) != set.find(u))
                {
                    set.un(v, u);
                    l[edgen++] = edge;
                }
            }
            else
            {
                return l;
            }
        }
        return l;
    }
    void dijkstra(int s, T d[], int path[])
    {
        int n = vnum;
        int i, j;
        int mark[n];
        for (i = 0; i < n; i++)
        {
            mark[i] = 0;
            d[i] = 100000;
            path[i] = -1;
        }
        mark[s] = 1;
        d[s] = 0;
        path[s] = s;
        for (i = 0; i < n; i++)
        {
            T min = 100000;
            int k = 0;
            for (j = 1; j < n; j++)
            {
                if (mark[j] == 0 && min > d[j])
                {
                    min = d[j];
                    k = j;
                }
            }
            /*cout<<k<<endl;
            for(int m = 0;m < n;m++){
                cout<<d[m]<<' ';
            }
            cout<<endl;
            for(int m = 0;m < n;m++){
                cout<<path[m]<<' ';
            }
            cout<<endl;*/
            mark[k] = 1;
            for (j = 0; j < n; j++)
            {
                if (map[k][j] != 0)
                {
                    if (mark[j] == 0 && (d[j] > (d[k] + map[k][j])))
                    {
                        d[j] = d[k] + map[k][j];
                        path[j] = k;
                    }
                }
            }
        }
    }
    void floyd(T **adj, int **path)
    {
        int i, j, v;
        int n = vnum;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == j)
                {
                    adj[i][j] = 0;
                    path[i][j] = i;
                }
                else
                {
                    adj[i][j] = 10000;
                    path[i][j] = -1;
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (map[i][j] != 0)
                {
                    adj[i][j] = map[i][j];
                    path[i][j] = i;
                }
            }
        }
        for (v = 0; v < n; v++)
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    if (adj[i][j] > (adj[i][v] + adj[v][j]))
                    {
                        adj[i][j] = adj[i][v] + adj[v][j];
                        path[i][j] = v;
                    }
    }
    void findloop1(int *mark)
    {
        int n = vnum;
        int *in = new int[n];
        int i, j, k;
        for (i = 0; i < n; i++)
        {
            in[i] = 0;
            mark[i] = 0;
        }
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (map[i][j] != 0)
                    in[j]++;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (in[j] == 0 && mark[j] == 0)
                    break;
            }
            if (j == n)
                return;
            mark[j] = 1;
            for (k = 0; k < n; k++)
            {
                if (map[j][k] != 0)
                {
                    in[k]--;
                }
            }
        }
    }
    void findloop2(int *mark)
    {
        int n = vnum;
        int *out = new int[n];
        int i, j, k;
        for (i = 0; i < n; i++)
        {
            mark[i] = 0;
        }
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (map[i][j] != 0)
                    out[i]++;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (out[j] == 0 && mark[j] == 0)
                    break;
            }
            if (j == n)
                return;
            mark[j] = 1;
            for (k = 0; k < n; k++)
            {
                if (map[k][j] != 0)
                {
                    out[k]--;
                }
            }
        }
    }
};
int main()
{
    int num;
    cin >> num;
    Graph<int> g(num);
    /*int s;
    cin>>s;
    g.dijkstra(s,l,p);
    for(int i = 0;i < num;i++){
        if(p[i] == -1){
            cout<<"no path"<<endl;
            continue;
        }
        cout<<l[i]<<' ';
        int k = i;
        cout<<'v'<<k;
        while(p[k] != s){
            cout<<" <- v"<<p[k];
            k = p[k];
        }
        cout<<" <- v"<<s<<endl;
    }*/
    /*int** l, **p;
    int i,j;
    l = new int*[num];
    p = new int*[num];
    for(i = 0;i < num;i++){
        l[i] = new int[num];
        p[i] = new int[num];
    }
    g.floyd(l,p);
    for(i = 0;i < num;i++){
        for(j = 0;j < num;j++){
            if(l[i][j] == 10000)
                cout<<'n'<<' ';
            else
                cout<<l[i][j]<<' ';
        }
        cout<<'\t';
        for(j = 0;j < num;j++){
            cout<<p[i][j]<<' ';
        }
        cout<<endl;
    }*/
    int *l = new int[num];
    int i, k, j, n;
    g.findloop1(l);
    g.findloop2(l);
    i = 0;
    while (l[i] != 0 && i < num)
        i++;
    if (i == num)
    {
        cout << "no";
        return 0;
    }
    n = i;
    for (k = 0; k < num; k++)
    {
        if (g.map[n][k] != 0 && l[k] == 0)
        {
            j = k;
            break;
        }
    }
    cout << i;
    while (j != n)
    {
        cout << "->" << j;
        for (k = 0; k < num; k++)
        {
            if (g.map[j][k] != 0 && l[k] == 0)
            {
                i = j;
                j = k;
                break;
            }
        }
    }
    return 0;
}
