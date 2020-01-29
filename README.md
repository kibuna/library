# library
[![Actions Status](https://github.com/kibuna/library/workflows/verify/badge.svg)](https://github.com/kibuna/library/actions)

[Verification status](https://kibuna.github.io/library/)

## これはなに
[kibuna](https://atcoder.jp/users/kibuna)が競技プログラミングで使っているライブラリとそのVSCode用スニペットです。

- library
  - データ構造とアルゴリズムを構造体や関数にしたものです。
- snippets
  - スニペットとして使うコードの断片です。VSCodeのプレースホルダが含まれていることがあります。
- test
  - [Online Judge Verify Helper](https://github.com/kmyk/online-judge-verify-helper)で実行できるテスト用コードです。
- cpp.json
  - VSCodeで使うスニペットの定義ファイルです。[autolibrary](https://github.com/ngtkana/autolibrary)をお借りして作成しています。
    - autolibrary直下で ```cargo run .. ```すると、libraryとsnippetsに含まれるファイルからcpp.jsonが生成されます。
  - verify-helperのbundleを使ってincludeを展開してからスニペットに変換するようにしてみましたが、Rustがわからなすぎるためかなり愚直っぽいです。
