# ford_fulkerson
最大流をO(EF)で求める。Fは最大流
## usage
ff.add_edge(a, b, w)で頂点a, b間に容量wの有向辺を張る。ff.max_flow(s, t)でsからtの最大流を求める。注意点として、一度フローを流すと内部変数が変化するので複数の(s, t)について最大流を求めたいときはコピーしてからフローを流す。
## verified
https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A

# dinic
最大流をO(EV^2)で求める。
## usage
DirectedGraph(V)で頂点数Vの有向グラフを初期化。  
g.add_edge(a, b, w)で頂点a, b間に容量wの有向辺を張る。ff.max_flow(s, t)でsからtの最大流を求める。注意点として、一度フローを流すと内部変数が変化するので複数の(s, t)について最大流を求めたいときはコピーしてからフローを流す。
## verified
https://onlinejudge.u-aizu.ac.jp/status/users/knshnb/submissions/1/3058/judge/3418800/C++14