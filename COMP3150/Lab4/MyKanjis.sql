CREATE TABLE Stroke (
   Id INTEGER PRIMARY KEY AUTOINCREMENT,
   Number INTEGER NOT NULL,
   CONSTRAINT UK_Number UNIQUE(Number)
   );

CREATE TABLE Kanji (
   Unicode INTEGER PRIMARY KEY,
   Type VARCHAR(255) NULL,
   JlptLevel VARCHAR(255) NULL,
   Character NVARCHAR(100) NOT NULL,
   StrokeId INTEGER NOT NULL REFERENCES Stroke(Id)
   );

CREATE TABLE AreMadeOfKanji (
   LargeKanji INTEGER NOT NULL,
   RadicalKanji INTEGER NOT NULL,
   PRIMARY KEY (LargeKanji, RadicalKanji),
   CONSTRAINT FK_AreMadeOfKanji_LargeKanji_2_Kanji_Unicode FOREIGN KEY(LargeKanji) REFERENCES Kanji(Unicode),
   CONSTRAINT FK_AreMadeOfKanji_RadicalKanji_2_Kanji_Unicode FOREIGN KEY(RadicalKanji) REFERENCES Kanji(Unicode)
   );

CREATE TABLE Meaning (
   Id INTEGER PRIMARY KEY AUTOINCREMENT,
   Means VARCHAR(255) NOT NULL
   );

CREATE TABLE KanjiMeaning (
   MeaningId INTEGER NOT NULL,
   KanjiId INTEGER NOT NULL,
   CONSTRAINT FK_KanjiMeaning_MeaningId_2_Meaning_Id FOREIGN KEY(MeaningId) REFERENCES Meaning(Id),
   CONSTRAINT FK_KanjiMeaning_KanjiId_2_Kanji_Unicode FOREIGN KEY(KanjiId) REFERENCES Kanji(Unicode),
   PRIMARY KEY (MeaningId, KanjiId)
   );

CREATE TABLE IsSimilarToKanji (
   SourceKanji INTEGER NOT NULL,
   DestKanji INTEGER NOT NULL,
   PRIMARY KEY(SourceKanji, DestKanji),
   CONSTRAINT FK_IsSimilarToKanji_SourceKanji_2_Kanji_Unicode FOREIGN KEY (SourceKanji) REFERENCES Kanji(Unicode),
   CONSTRAINT FK_IsSimilarToKanji_DestKanji_2_Kanji_Unicode FOREIGN KEY (DestKanji) REFERENCES Kanji(Unicode)
   );

CREATE TABLE Examples (
   Id INTEGER PRIMARY KEY AUTOINCREMENT,
   Sentence NVARCHAR(100) NULL,
   Meaning VARCHAR(255) NULL
   );

CREATE TABLE KanjiExamples (
   KanjiId INTEGER NOT NULL,
   ExampleId INTEGER NOT NULL,
   PRIMARY KEY (KanjiId, ExampleId),
   CONSTRAINT FK_KanjiExamples_KanjiId_2_Kanji_Unicode FOREIGN KEY (KanjiId) REFERENCES Kanji(Unicode),
   CONSTRAINT FK_KanjiExamples_ExampleId_2_Examples_Id FOREIGN KEY (ExampleId) REFERENCES Examples(Id)
   );

CREATE TABLE Kunyomi (
   Id INTEGER PRIMARY KEY AUTOINCREMENT,
   Romaji VARCHAR(255) NULL,
   Hiragana NVARCHAR(100) NULL,
   Katakana NVARCHAR(100) NULL
   );

CREATE TABLE KanjiKunyomi (
   KanjiId INTEGER NOT NULL,
   KunyomiId INTEGER NOT NULL,
   PRIMARY KEY (KanjiId, KunyomiId),
   CONSTRAINT FK_KanjiKunyomi_KanjiId_2_Kanji_Unicode FOREIGN KEY (KanjiId) REFERENCES Kanji(Unicode),
   CONSTRAINT FK_KanjiKunyomi_KunyomiId_2_Kunyomi_Id FOREIGN KEY (KunyomiId) REFERENCES Kunyomi(Id)
   );

CREATE TABLE Onyomi (
   Id INTEGER PRIMARY KEY AUTOINCREMENT,
   Romaji VARCHAR(255) NULL,
   Hiragana NVARCHAR(100) NULL,
   Katakana NVARCHAR(100) NULL
   );

CREATE TABLE KanjiOnyomi (
   KanjiId INTEGER NOT NULL,
   OnyomiId INTEGER NOT NULL,
   PRIMARY KEY (KanjiId, OnyomiId),
   CONSTRAINT FK_KanjiOnyomi_KanjiId_2_Kanji_Unicode FOREIGN KEY (KanjiId) REFERENCES Kanji(Unicode),
   CONSTRAINT FK_KanjiOnyomi_OnyomiId_2_Onyomi_Id FOREIGN KEY (OnyomiId) REFERENCES Onyomi(Id)
   );

CREATE TABLE SingleReading (
   Id INTEGER PRIMARY KEY AUTOINCREMENT,
   Romaji VARCHAR(255) NOT NULL,
   Hiragana NVARCHAR(100) NOT NULL,
   Katakana NVARCHAR(100) NOT NULL
   );

CREATE TABLE Compounds (
   Id INTEGER PRIMARY KEY AUTOINCREMENT,
   KanjiString NVARCHAR(100) NOT NULL,
   Means VARCHAR(255) NOT NULL,
   SingleReadingId INTEGER NOT NULL REFERENCES SingleReading(Id),
   CONSTRAINT UK_KanjiString UNIQUE(KanjiString)
   );

CREATE TABLE KanjiMakeUpCompounds (
   KanjiId INTEGER NOT NULL,
   CompoundId INTEGER NOT NULL,
   CompoundString VARCHAR(255) NOT NULL,
   CONSTRAINT FK_KanjiMakeUpCompounds_KanjiId_2_Kanji_Unicode FOREIGN KEY (KanjiId) REFERENCES Kanji(Unicode),
   CONSTRAINT FK_KanjiMakeUpCompounds_CompoundId_2_Compounds_Id FOREIGN KEY (CompoundId) REFERENCES Compounds(Id),
   CONSTRAINT FK_KanjiMakeUpCompounds_CompoundString_2_Compounds_KanjiString FOREIGN KEY (CompoundString) REFERENCES Compounds(KanjiString),
   PRIMARY KEY (KanjiId, CompoundId, CompoundString)
   );

INSERT INTO Stroke(Number) VALUES (1);
INSERT INTO Stroke(Number) VALUES (2);
INSERT INTO Stroke(Number) VALUES (3);
INSERT INTO Stroke(Number) VALUES (4);
INSERT INTO Stroke(Number) VALUES (5);
INSERT INTO Stroke(Number) VALUES (6);
INSERT INTO Stroke(Number) VALUES (7);
INSERT INTO Stroke(Number) VALUES (8);
INSERT INTO Stroke(Number) VALUES (9);
INSERT INTO Stroke(Number) VALUES (10);

-- The CJK characters here will not display in cmd. Read the ReadMe.txt included if you want to see
-- the way I got them to display when exported to excel, or you can use your own way. The characters
-- are in UTF-8. I think they work in powershell ISE (Not regular powershell), but I cannot run commands after starting sqlite3
-- and I am not sure why.
INSERT INTO Kanji(Unicode, Type, JlptLevel, Character, StrokeId) VALUES (19968, 'Jōyō', 'N5', '一', 1);
INSERT INTO Kanji(Unicode, Type, JlptLevel, Character, StrokeId) VALUES (20309, 'Jōyō', 'N5', '何', 7);
INSERT INTO Kanji(Unicode, Type, JlptLevel, Character, StrokeId) VALUES (39135, 'Jōyō', 'N5', '食', 9);
INSERT INTO Kanji(Unicode, Type, JlptLevel, Character, StrokeId) VALUES (30007, 'Jōyō', 'N5', '男', 7);
INSERT INTO Kanji(Unicode, Type, JlptLevel, Character, StrokeId) VALUES (22899, 'Jōyō', 'N5', '女', 3);
INSERT INTO Kanji(Unicode, Type, JlptLevel, Character, StrokeId) VALUES (20154, 'Jōyō', 'N5', '人', 2);
INSERT INTO Kanji(Unicode, Type, JlptLevel, Character, StrokeId) VALUES (26178, 'Jōyō', 'N5', '時', 10);
INSERT INTO Kanji(Unicode, Type, JlptLevel, Character, StrokeId) VALUES (26085, 'Jōyō', 'N5', '日', 4);
INSERT INTO Kanji(Unicode, Type, JlptLevel, Character, StrokeId) VALUES (26412, 'Jōyō', 'N5', '本', 5);
INSERT INTO Kanji(Unicode, Type, JlptLevel, Character, StrokeId) VALUES (26408, 'Jōyō', 'N5', '木', 4);
INSERT INTO Kanji(Unicode, Type, JlptLevel, Character, StrokeId) VALUES (20803, 'Jōyō', 'N4', '元', 4);
INSERT INTO Kanji(Unicode, Type, JlptLevel, Character, StrokeId) VALUES (20108, 'Jōyō', 'N5', '二', 2);
INSERT INTO Kanji(Unicode, Type, JlptLevel, Character, StrokeId) VALUES (20799, NULL, NULL, '儿', 2);

INSERT INTO AreMadeOfKanji(LargeKanji, RadicalKanji) VALUES (26178, 26085);
INSERT INTO AreMadeOfKanji(LargeKanji, RadicalKanji) VALUES (26412, 26408);
INSERT INTO AreMadeOfKanji(LargeKanji, RadicalKanji) VALUES (26412, 19968);
INSERT INTO AreMadeOfKanji(LargeKanji, RadicalKanji) VALUES (20803, 20799);
INSERT INTO AreMadeOfKanji(LargeKanji, RadicalKanji) VALUES (20803, 20108);

INSERT INTO Meaning(Means) VALUES ('one');
INSERT INTO Meaning(Means) VALUES ('what');
INSERT INTO Meaning(Means) VALUES ('eat');
INSERT INTO Meaning(Means) VALUES ('man');
INSERT INTO Meaning(Means) VALUES ('women');
INSERT INTO Meaning(Means) VALUES ('person');
INSERT INTO Meaning(Means) VALUES ('time');
INSERT INTO Meaning(Means) VALUES ('day');
INSERT INTO Meaning(Means) VALUES ('sun');
INSERT INTO Meaning(Means) VALUES ('book');
INSERT INTO Meaning(Means) VALUES ('tree');
INSERT INTO Meaning(Means) VALUES ('origin');
INSERT INTO Meaning(Means) VALUES ('two');

INSERT INTO KanjiMeaning(MeaningId, KanjiId) VALUES (1, 19968);
INSERT INTO KanjiMeaning(MeaningId, KanjiId) VALUES (2, 20309);
INSERT INTO KanjiMeaning(MeaningId, KanjiId) VALUES (3, 39135);
INSERT INTO KanjiMeaning(MeaningId, KanjiId) VALUES (4, 30007);
INSERT INTO KanjiMeaning(MeaningId, KanjiId) VALUES (5, 22899);
INSERT INTO KanjiMeaning(MeaningId, KanjiId) VALUES (6, 20154);
INSERT INTO KanjiMeaning(MeaningId, KanjiId) VALUES (7, 26178);
INSERT INTO KanjiMeaning(MeaningId, KanjiId) VALUES (8, 26085);
INSERT INTO KanjiMeaning(MeaningId, KanjiId) VALUES (9, 26085);
INSERT INTO KanjiMeaning(MeaningId, KanjiId) VALUES (10, 26412);
INSERT INTO KanjiMeaning(MeaningId, KanjiId) VALUES (11, 26408);
INSERT INTO KanjiMeaning(MeaningId, KanjiId) VALUES (12, 20803);
INSERT INTO KanjiMeaning(MeaningId, KanjiId) VALUES (13, 20108);

INSERT INTO Examples(Sentence, Meaning) VALUES ('毎日, 僕は一人', 'Everyday, I am alone');
INSERT INTO Examples(Sentence, Meaning) VALUES ('何が人生のいみ？', 'What is the meaning of life?');
INSERT INTO Examples(Sentence, Meaning) VALUES ('食べる？', 'Do you want food?');
INSERT INTO Examples(Sentence, Meaning) VALUES ('私は男です', 'I am a man');
INSERT INTO Examples(Sentence, Meaning) VALUES ('その女はめっちゃ美人', 'That girl is very beautiful');

INSERT INTO KanjiExamples(KanjiId, ExampleId) VALUES (19968, 1);
INSERT INTO KanjiExamples(KanjiId, ExampleId) VALUES (20154, 1);
INSERT INTO KanjiExamples(KanjiId, ExampleId) VALUES (26085, 1);
INSERT INTO KanjiExamples(KanjiId, ExampleId) VALUES (20309, 2);
INSERT INTO KanjiExamples(KanjiId, ExampleId) VALUES (39135, 3);
INSERT INTO KanjiExamples(KanjiId, ExampleId) VALUES (30007, 4);
INSERT INTO KanjiExamples(KanjiId, ExampleId) VALUES (22899, 5);

-- The hiragana and katakana won't work in cmd either (Or powershell)

INSERT INTO Kunyomi(Romaji, Hiragana, Katakana) VALUES ('hito', 'ひと', 'ヒト');
INSERT INTO Kunyomi(Romaji, Hiragana, Katakana) VALUES ('nani', 'なに', 'ナニ');
INSERT INTO Kunyomi(Romaji, Hiragana, Katakana) VALUES ('nan', 'なん', 'ナン');
INSERT INTO Kunyomi(Romaji, Hiragana, Katakana) VALUES ('ku', 'く', 'ク');
INSERT INTO Kunyomi(Romaji, Hiragana, Katakana) VALUES ('ta', 'た', 'タ');
INSERT INTO Kunyomi(Romaji, Hiragana, Katakana) VALUES ('ha', 'は', 'ハ');

INSERT INTO KanjiKunyomi(KanjiId, KunyomiId) VALUES (19968, 1);
INSERT INTO KanjiKunyomi(KanjiId, KunyomiId) VALUES (20309, 2);
INSERT INTO KanjiKunyomi(KanjiId, KunyomiId) VALUES (20309, 3);
INSERT INTO KanjiKunyomi(KanjiId, KunyomiId) VALUES (39135, 4);
INSERT INTO KanjiKunyomi(KanjiId, KunyomiId) VALUES (39135, 5);
INSERT INTO KanjiKunyomi(KanjiId, KunyomiId) VALUES (39135, 6);

INSERT INTO Onyomi(Romaji, Hiragana, Katakana) VALUES ('ichi', 'いち', 'イチ');
INSERT INTO Onyomi(Romaji, Hiragana, Katakana) VALUES ('itsu', 'いつ', 'イツ');
INSERT INTO Onyomi(Romaji, Hiragana, Katakana) VALUES ('ka', 'か', 'カ');
INSERT INTO Onyomi(Romaji, Hiragana, Katakana) VALUES ('shoku', 'しょく', 'ショク');
INSERT INTO Onyomi(Romaji, Hiragana, Katakana) VALUES ('jiki', 'じき', 'ジキ');

INSERT INTO KanjiOnyomi(KanjiId, OnyomiId) VALUES (19968, 1);
INSERT INTO KanjiOnyomi(KanjiId, OnyomiId) VALUES (19968, 2);
INSERT INTO KanjiOnyomi(KanjiId, OnyomiId) VALUES (20309, 3);
INSERT INTO KanjiOnyomi(KanjiId, OnyomiId) VALUES (39135, 4);
INSERT INTO KanjiOnyomi(KanjiId, OnyomiId) VALUES (39135, 5);

INSERT INTO SingleReading(Romaji, Hiragana, Katakana) VALUES ('jyakunikukyoushoku', 'じゃくにくきょうしょく', 'ジャクニクキョーショク');
INSERT INTO SingleReading(Romaji, Hiragana, Katakana) VALUES ('mukanjyou', 'むかんじょう', 'ムカンジョー');
INSERT INTO SingleReading(Romaji, Hiragana, Katakana) VALUES ('ongaku', 'おんがく', 'オンガク');
INSERT INTO SingleReading(Romaji, Hiragana, Katakana) VALUES ('mangaka', 'まんがか', 'マンガカ');
INSERT INTO SingleReading(Romaji, Hiragana, Katakana) VALUES ('shokuyoku', 'しょくよく', 'ショクヨク');
INSERT INTO SingleReading(Romaji, Hiragana, Katakana) VALUES ('ichiban', 'いちばん', 'イチバン');
INSERT INTO SingleReading(Romaji, Hiragana, Katakana) VALUES ('danjyo', 'だんじょ', 'ダンジョ');

INSERT INTO Compounds(KanjiString, Means, SingleReadingId) VALUES ('弱肉強食', 'Survival of the fittest', 1);
INSERT INTO Compounds(KanjiString, Means, SingleReadingId) VALUES ('無感情', 'Apathy', 2);
INSERT INTO Compounds(KanjiString, Means, SingleReadingId) VALUES ('音楽', 'music', 3);
INSERT INTO Compounds(KanjiString, Means, SingleReadingId) VALUES ('漫画家', 'manga artist', 4);
INSERT INTO Compounds(KanjiString, Means, SingleReadingId) VALUES ('食欲', 'appetite', 5);
INSERT INTO Compounds(KanjiString, Means, SingleReadingId) VALUES ('一番', 'most', 6);
INSERT INTO Compounds(KanjiString, Means, SingleReadingId) VALUES ('男女', 'both genders', 7);

INSERT INTO KanjiMakeUpCompounds(KanjiId, CompoundId, CompoundString) VALUES (39135, 1, '弱肉強食');
INSERT INTO KanjiMakeUpCompounds(KanjiId, CompoundId, CompoundString) VALUES (39135, 5, '食欲');
INSERT INTO KanjiMakeUpCompounds(KanjiId, CompoundId, CompoundString) VALUES (19968, 6, '一番');
INSERT INTO KanjiMakeUpCompounds(KanjiId, CompoundId, CompoundString) VALUES (30007, 7, '男女');
INSERT INTO KanjiMakeUpCompounds(KanjiId, CompoundId, CompoundString) VALUES (22899, 7, '男女');