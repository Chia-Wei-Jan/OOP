1. 姓名: 冉家維
2. 學號: 407420088
3. e-mail: asd12398713@gmail.com

4. 完成的作業項目
   (1) C++: 檔案名稱為Coin.cpp, Coin.h, main.cpp
   (2) makefile: 編譯和清除執行檔

5. Bouns內容(助教會依Bonus內容酌量給分)
   (1) Coding style和作業完整度
	(i) 有寫註解及設計排版
	(ii) 將 dollar, cent, q, d, n, s宣告在private，使得不能從class外部輕易動到
	(iii) 將 display function宣告成constant member

   (2) 防呆機制處理
	英文輸入、超過兩位小數點、特殊符號(!, %, &)、沒給argv[1]

   (3) constructor 和 destrurctor
	依照老師說的在constructor印出"object is being created"，在destructor印出"object is being deleted"，
	去體會和確保constructor和destructor有被正確使用。
	就算是錯誤輸入也沒有直接exit程式，而是有先呼叫destructor。

   (4) 撰寫第二種語言(Python)，檔案名稱為 main.py, Coin.py
	class寫在 Coin.py，執行 main.py即可 (會call Coin.py)
	第二種語言同樣有滿足上述(1)(2)(3) bonus項目

