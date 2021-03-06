#include "keywords.h"
#include "sqlite3_parse.h"
#include <QDebug>
#include <QList>

QHash<QString,int> keywords3;
QSet<QString> rowIdKeywords;
QStringList joinKeywords;
QStringList fkMatchKeywords;
QStringList conflictAlgoKeywords;

int getKeywordId3(const QString& str)
{
    QString upStr = str.toUpper();
    if (keywords3.contains(upStr))
        return keywords3[upStr];
    else
        return TK3_ID;
}

bool isRowIdKeyword(const QString& str)
{
    return rowIdKeywords.contains(str.toUpper());
}

const QHash<QString,int>& getKeywords3()
{
    return keywords3;
}

void initKeywords()
{
    // SQLite 3
    keywords3["REINDEX"] = TK3_REINDEX;
    keywords3["INDEXED"] = TK3_INDEXED;
    keywords3["INDEX"] = TK3_INDEX;
    keywords3["DESC"] = TK3_DESC;
    keywords3["ESCAPE"] = TK3_ESCAPE;
    keywords3["EACH"] = TK3_EACH;
    keywords3["CHECK"] = TK3_CHECK;
    keywords3["KEY"] = TK3_KEY;
    keywords3["BEFORE"] = TK3_BEFORE;
    keywords3["FOREIGN"] = TK3_FOREIGN;
    keywords3["FOR"] = TK3_FOR;
    keywords3["IGNORE"] = TK3_IGNORE;
    keywords3["REGEXP"] = TK3_LIKE_KW;
    keywords3["EXPLAIN"] = TK3_EXPLAIN;
    keywords3["INSTEAD"] = TK3_INSTEAD;
    keywords3["ADD"] = TK3_ADD;
    keywords3["DATABASE"] = TK3_DATABASE;
    keywords3["AS"] = TK3_AS;
    keywords3["SELECT"] = TK3_SELECT;
    keywords3["TABLE"] = TK3_TABLE;
    keywords3["LEFT"] = TK3_JOIN_KW;
    keywords3["THEN"] = TK3_THEN;
    keywords3["END"] = TK3_END;
    keywords3["DEFERRABLE"] = TK3_DEFERRABLE;
    keywords3["ELSE"] = TK3_ELSE;
    keywords3["EXCEPT"] = TK3_EXCEPT;
    keywords3["TRANSACTION"] = TK3_TRANSACTION;
    keywords3["ACTION"] = TK3_ACTION;
    keywords3["ON"] = TK3_ON;
    keywords3["NATURAL"] = TK3_JOIN_KW;
    keywords3["ALTER"] = TK3_ALTER;
    keywords3["RAISE"] = TK3_RAISE;
    keywords3["EXCLUSIVE"] = TK3_EXCLUSIVE;
    keywords3["EXISTS"] = TK3_EXISTS;
    keywords3["SAVEPOINT"] = TK3_SAVEPOINT;
    keywords3["INTERSECT"] = TK3_INTERSECT;
    keywords3["TRIGGER"] = TK3_TRIGGER;
    keywords3["REFERENCES"] = TK3_REFERENCES;
    keywords3["CONSTRAINT"] = TK3_CONSTRAINT;
    keywords3["INTO"] = TK3_INTO;
    keywords3["OFFSET"] = TK3_OFFSET;
    keywords3["OF"] = TK3_OF;
    keywords3["SET"] = TK3_SET;
    keywords3["TEMP"] = TK3_TEMP;
    keywords3["TEMPORARY"] = TK3_TEMP;
    keywords3["OR"] = TK3_OR;
    keywords3["UNIQUE"] = TK3_UNIQUE;
    keywords3["QUERY"] = TK3_QUERY;
    keywords3["ATTACH"] = TK3_ATTACH;
    keywords3["HAVING"] = TK3_HAVING;
    keywords3["GROUP"] = TK3_GROUP;
    keywords3["UPDATE"] = TK3_UPDATE;
    keywords3["BEGIN"] = TK3_BEGIN;
    keywords3["INNER"] = TK3_JOIN_KW;
    keywords3["RELEASE"] = TK3_RELEASE;
    keywords3["BETWEEN"] = TK3_BETWEEN;
    keywords3["NOTNULL"] = TK3_NOTNULL;
    keywords3["NOT"] = TK3_NOT;
    keywords3["NO"] = TK3_NO;
    keywords3["DO"] = TK3_DO;
    keywords3["NOTHING"] = TK3_NOTHING;
    keywords3["NULL"] = TK3_NULL;
    keywords3["LIKE"] = TK3_LIKE_KW;
    keywords3["CASCADE"] = TK3_CASCADE;
    keywords3["ASC"] = TK3_ASC;
    keywords3["DELETE"] = TK3_DELETE;
    keywords3["CASE"] = TK3_CASE;
    keywords3["COLLATE"] = TK3_COLLATE;
    keywords3["CREATE"] = TK3_CREATE;
    keywords3["CURRENT_DATE"] = TK3_CTIME_KW;
    keywords3["DETACH"] = TK3_DETACH;
    keywords3["IMMEDIATE"] = TK3_IMMEDIATE;
    keywords3["JOIN"] = TK3_JOIN;
    keywords3["INSERT"] = TK3_INSERT;
    keywords3["MATCH"] = TK3_MATCH;
    keywords3["PLAN"] = TK3_PLAN;
    keywords3["ANALYZE"] = TK3_ANALYZE;
    keywords3["PRAGMA"] = TK3_PRAGMA;
    keywords3["ABORT"] = TK3_ABORT;
    keywords3["VALUES"] = TK3_VALUES;
    keywords3["VIRTUAL"] = TK3_VIRTUAL;
    keywords3["LIMIT"] = TK3_LIMIT;
    keywords3["WHEN"] = TK3_WHEN;
    keywords3["WHERE"] = TK3_WHERE;
    keywords3["RENAME"] = TK3_RENAME;
    keywords3["AFTER"] = TK3_AFTER;
    keywords3["REPLACE"] = TK3_REPLACE;
    keywords3["AND"] = TK3_AND;
    keywords3["DEFAULT"] = TK3_DEFAULT;
    keywords3["AUTOINCREMENT"] = TK3_AUTOINCR;
    keywords3["TO"] = TK3_TO;
    keywords3["IN"] = TK3_IN;
    keywords3["CAST"] = TK3_CAST;
    keywords3["COLUMN"] = TK3_COLUMNKW;
    keywords3["COMMIT"] = TK3_COMMIT;
    keywords3["CONFLICT"] = TK3_CONFLICT;
    keywords3["CROSS"] = TK3_JOIN_KW;
    keywords3["CURRENT_TIMESTAMP"] = TK3_CTIME_KW;
    keywords3["CURRENT_TIME"] = TK3_CTIME_KW;
    keywords3["PRIMARY"] = TK3_PRIMARY;
    keywords3["DEFERRED"] = TK3_DEFERRED;
    keywords3["DISTINCT"] = TK3_DISTINCT;
    keywords3["IS"] = TK3_IS;
    keywords3["DROP"] = TK3_DROP;
    keywords3["FAIL"] = TK3_FAIL;
    keywords3["FROM"] = TK3_FROM;
    keywords3["FULL"] = TK3_JOIN_KW;
    keywords3["GLOB"] = TK3_LIKE_KW;
    keywords3["BY"] = TK3_BY;
    keywords3["IF"] = TK3_IF;
    keywords3["ISNULL"] = TK3_ISNULL;
    keywords3["ORDER"] = TK3_ORDER;
    keywords3["RESTRICT"] = TK3_RESTRICT;
    keywords3["OUTER"] = TK3_JOIN_KW;
    keywords3["RIGHT"] = TK3_JOIN_KW;
    keywords3["ROLLBACK"] = TK3_ROLLBACK;
    keywords3["ROW"] = TK3_ROW;
    keywords3["UNION"] = TK3_UNION;
    keywords3["USING"] = TK3_USING;
    keywords3["VACUUM"] = TK3_VACUUM;
    keywords3["VIEW"] = TK3_VIEW;
    keywords3["INITIALLY"] = TK3_INITIALLY;
    keywords3["WITHOUT"] = TK3_WITHOUT;
    keywords3["ALL"] = TK3_ALL;
    keywords3["WITH"] = TK3_WITH;
    keywords3["RECURSIVE"] = TK3_RECURSIVE;

    rowIdKeywords << "_ROWID_"
                  << "ROWID"
                  << "OID";


    joinKeywords << "NATURAL" << "LEFT" << "RIGHT" << "OUTER" << "INNER" << "CROSS";
    fkMatchKeywords << "SIMPLE" << "FULL" << "PARTIAL";
    conflictAlgoKeywords << "ROLLBACK" << "ABORT" << "FAIL" << "IGNORE" << "REPLACE";
}


bool isJoinKeyword(const QString &str)
{
    return joinKeywords.contains(str, Qt::CaseInsensitive);
}

QStringList getJoinKeywords()
{
    return joinKeywords;
}

QStringList getFkMatchKeywords()
{
    return fkMatchKeywords;
}

bool isFkMatchKeyword(const QString &str)
{
    return fkMatchKeywords.contains(str);
}

bool isKeyword(const QString& str)
{
    return keywords3.contains(str.toUpper());
}

QStringList getConflictAlgorithms()
{
    return conflictAlgoKeywords;
}
