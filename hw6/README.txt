1. 姓名: 冉家維
2. 學號: 407420088
3. e-mail: asd12398713@gmail.com

4. 完成的作業項目
   (1) cpp: 檔名為 main.cpp Game.cpp Card.cpp Deck.cpp Player.cpp Human.cpp Meek.cpp Random.cpp Dealer.cpp
   (2) header file: 檔名為 Game.h Card.h Deck.h Player.h Human.h Meek.h Random.h Dealer.h
   (3) makefile: 編譯和清除執行檔

5. Bouns內容(助教會依Bonus內容酌量給分)
   (1) 排版整齊
   (2) 有寫註解
   (3) 有將不會動到的常數設為 const int
   (4) 將變數放在 private，透過set和get去取變數，做到保護功能
   (5) 問是否要抽牌有做防呆 (顯示Invalid Input)
   (6) 問是否要下一局有做防呆 (顯示Invalid Input)
   (7) 確實利用 inheritance 解決多種不同的 Player問題
   (8) 使用 virtual function
   (9) 關於Ace的點數要選擇 1 或 11，在Class Player中的compute_totalPoint()有完整計算，確保各種可能
   (10) 有拆分各個 class 到不同 cpp 和 header file，因為使用到繼承一開始會有重複定義問題，後來在.h加上
         # ifndef, #define, #endif 解決問題
   (11) 有確實依照slide上當牌數小於玩家數的5倍要重新整理牌，否則就只有用剩餘的牌洗牌
   (12) README 詳細完整


玩法:	
	我的gamesetting寫在Game的constructor
	作業顯示跟slide的範例差不多，一開始會要求輸入總玩家數和真實玩家數，並會將剩餘電腦玩家平均分配到
        meek和random。之後會要求輸入真實玩家人名和資產，而meek和random的資產本遊戲都訂為100，人名將由Meek1,
        Meek2, ...和 Random1, Random2, ...命名。

	遊戲開始前會問真實玩家下注金額，發兩張牌後問是否要繼續抽牌，輸入Y or N。
	遊戲結束會顯示輸贏多少錢和目前所有玩家剩餘金額，並問是否要下一句，輸入Y or N。
