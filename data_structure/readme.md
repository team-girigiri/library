# union_find
実質O(1)でunite, findができる。
## usage
unite, same, find, size関数がある。さらに、uf.cntで連結成分の個数がわかる。
## verified
https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A

# sparse_table
RMQを構築O(NlogN), クエリO(1)で返す。
## verified
https://www.spoj.com/submit/RMQSQ/

# implicit_treap
O(logN)で配列のランダムアクセス、任意箇所への挿入、削除、RMQ, RUQなどができる。
## usage
型はImplicitTreap<MinMonoid, UpdateMonoid>のように宣言。この型を使うと、例えばImplicitTreap上の二分探索により
半開区間[l, r)におけるx未満の最左/最右の要素の位置をO(logN)で得ることができる。詳細はコメントを参照
## verified
https://atcoder.jp/contests/pakencamp-2018-day2/tasks/pakencamp_2018_day2_d
