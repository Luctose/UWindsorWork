-- Lab 4 Report
-- Lucas Sarweh
-- 110042658

-- I scrapped some of the questions (Thankfully I had more than 10) because they are impossible
-- to do without altering the tables

-- Lookup kanji by its meaning in English
-- Example meaning eat

SELECT Character
FROM Kanji
WHERE Unicode = (SELECT KanjiId
                FROM KanjiMeaning
                WHERE KanjiMeaning.MeaningId = (SELECT Id
                                                FROM Meaning
                                                WHERE Meaning.Means = 'eat'
                                                )
                );
-- This selects a character by referencing the Kanji in the KanjiMeaning table that have the
-- MeaningId that corresponds to the inputted meaning VARCHAR.


-- Lookup kanji(s) by its pronunciation (Onyomi / Kunyomi)
-- Example pronunciation hito

-- Kunyomi:
SELECT Character
FROM Kanji
WHERE Unicode = (SELECT KanjiId
                FROM KanjiKunyomi
                WHERE KanjiKunyomi.KunyomiId = (SELECT Id
                                                FROM Kunyomi
                                                WHERE Kunyomi.Romaji = 'hito' OR Kunyomi.Hiragana = 'hito' OR Kunyomi.Katakana = 'hito'
                                                )
                );
-- This selects a character by referencing the Kanji in the KanjiKunyomi table that have the
-- KunyomiId that corresponds to the inputted Kunyomi VARCHAR's (Either Romaji, Hiragana, or Katakana).

-- Onyomi:
SELECT Character
FROM Kanji
WHERE Unicode = (SELECT KanjiId
                FROM KanjiOnyomi
                WHERE KanjiOnyomi.OnyomiId = (SELECT Id
                                                FROM Onyomi
                                                WHERE Onyomi.Romaji = 'hito' OR Onyomi.Hiragana = 'hito' OR Onyomi.Katakana = 'hito'
                                                )
                );
-- This selects a character by referencing the Kanji in the KanjiOnyomi table that have the
-- OnyomiId that corresponds to the inputted Onyomi VARCHAR's (Either Romaji, Hiragana, or Katakana).

-- Lookup kanji by the number of strokes
-- Example stroke 7

SELECT Character
FROM Kanji
WHERE StrokeId = (SELECT Id
                FROM Stroke
                WHERE Stroke.Number = 7
                );
-- Selects a Character from a Kanji by referencing the StrokeId that goes to the Stroke table with the inputted Stroke Number.

-- Lookup kanji by its level for the JLPT (N5 – N1)
-- Example level N5

SELECT Character
FROM Kanji
WHERE JlptLevel = 'N5';
-- This Selects the Kanji's that have the inputted JlptLevel as JlptLevel is within the Kanji table.

-- What is a kanjis pronunciation (Onyomi / Kunyomi)
-- All of the next queries will have 人 as an example

-- You can replace Romaji with Hiragana or Katakana to get the pronunciation in those scripts

-- Onyomi:
SELECT Romaji
FROM Onyomi
WHERE Onyomi.Id = (SELECT OnyomiId
                    From KanjiOnyomi
                    WHERE KanjiOnyomi.KanjiId = (SELECT Unicode
                                                FROM Kanji
                                                WHERE Kanji.Character = '人'
                                                )
                    );
-- This selects a pronunciation by referencing the Id of an Onyomi entry and taking the Onyomi table's
-- KanjiId leading us to the Kanji table and referencing the Kanji Character given.

-- Kunyomi:
SELECT Romaji
FROM Kunyomi
WHERE Kunyomi.Id = (SELECT KunyomiId
                    From KanjiKunyomi
                    WHERE KanjiKunyomi.KanjiId = (SELECT Unicode
                                                FROM Kanji
                                                WHERE Kanji.Character = '人'
                                                )
                    );
-- This selects a pronunciation by referencing the Id of an Kunyomi entry and taking the Kunyomi table's
-- KanjiId leading us to the Kanji table and referencing the Kanji Character given.

-- What are a kanjis meaning

SELECT Means
FROM Meaning
WHERE Meaning.Id = (SELECT MeaningId
                    FROM KanjiMeaning
                    WHERE KanjiMeaning.KanjiId = (SELECT Unicode
                                                FROM Kanji
                                                WHERE Kanji.Character = '人'
                                                )
                    );
-- This selects a Meaning (Meaning.Means) by referencing the Id of an Meaning entry and taking the KanjiMeaning table's
-- KanjiId leading us to the Kanji table and referencing the Kanji Character given.

-- How many strokes a kanji has

SELECT Number
FROM Stroke
WHERE Stroke.Id = (SELECT StrokeId
                    From Kanji
                    WHERE Kanji.Character = '人'
                    );
-- This gives the Number of Strokes by using the Stroke Id and matching it with the StrokeId in the Kanji table
-- based off of what kanji you give.

-- What parts or radicals a kanji is made up of

SELECT RadicalKanji
FROM AreMadeOfKanji
WHERE AreMadeOfKanji.LargeKanji = (SELECT Unicode
                                    FROM Kanji
                                    WHERE Kanji.Character = '人'
                                    );
-- This gives the Radical Kanji by using the AreMadeOfKanji relation and matching the LargeKanji with the given Kanji in the
-- subquery and selecting the RadicalKanji associated.

-- What is an example of the kanji in a sentence

SELECT Sentence
FROM Examples
WHERE Examples.Id = (SELECT ExampleId
                    FROM KanjiExamples
                    WHERE KanjiExamples.KanjiId = (SELECT Unicode
                                                    From Kanji
                                                    WHERE Kanji.Character = '人'
                                                    )
                    );
-- This selects an Example Sentence by referencing the Id of the Examples table tied to the Sentence going to the
-- KanjiExamples table which has the Id of the Kanji we inpputed to get an example.