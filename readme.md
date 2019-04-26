# ライブラリの追加規則
- ファイル名は `snake_case.cpp`
- アルゴリズムの説明・verify問題・使用方法などを対応するフォルダの `readme.md` に記載

## readme.mdの例

```
# sparse_table
RMQを構築O(NlogN), クエリO(1)で返す。
## author
Joe
## usage
vector<T>でコンストラクト。query(l, r)で半開区間[l, r)について最小値クエリ
## verified
https://www.spoj.com/submit/RMQSQ/
```
