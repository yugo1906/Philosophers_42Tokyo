# Philosophers_42Tokyo
## 本リポジトリの概要
- 「食事する哲学者のシミュレーション」をマルチスレッド処理で実装

## デモ動画
https://github.com/yugo1906/Philosophers_42Tokyo/assets/89300571/bd6d82ac-5ea9-4e3d-8601-e529260c6b48

■動作実行時のコマンドライン引数についての説明。
- 第一引数：哲学者の数（ = フォークの数)
- 第二引数：最後の食事が開始してから、あるいはシミュレーションが開始してから「第二引数」ミリ秒以内に食事をしなかった場合、哲学者が餓死する
- 第三引数：哲学者が睡眠に費やす時間
- 第四引数：すべての哲学者が少なくとも「第四引数」回食事した場合、シミュレーションを停止する

## 実装の制約
- normというコーディング規約を必ず守ること（for文は禁止、Allmanスタイルで書く、などの様々なルールあり)
- 標準関数は課題で許可されているものしか使用できない
