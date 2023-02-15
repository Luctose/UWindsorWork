CREATE TABLE Stroke (
   Id INTEGER PRIMARY KEY AUTOINCREMENT,
   Number INTEGER NOT NULL,
   CONSTRAINT UK_Number UNIQUE(Number)
   );

CREATE TABLE Kanji (
   Unicode INTEGER PRIMARY KEY,
   Type VARCHAR(255) NULL,
   JlptLevel VARCHAR(255) NULL,
   Character VARCHAR(255) NOT NULL,
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
   Sentence VARCHAR(255) NULL,
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
   Hiragana VARCHAR(255) NULL,
   Katakana VARCHAR(255) NULL
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
   Hiragana VARCHAR(255) NULL,
   Katakana VARCHAR(255) NULL
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
   Hiragana VARCHAR(255) NOT NULL,
   Katakana VARCHAR(255) NOT NULL
   );

CREATE TABLE Compounds (
   Id INTEGER PRIMARY KEY AUTOINCREMENT,
   KanjiString VARCHAR(255) NOT NULL,
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