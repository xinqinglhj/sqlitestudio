#ifndef SQLEXPORT_H
#define SQLEXPORT_H

#include "plugins/genericexportplugin.h"
#include "sqlexport_global.h"
#include "config_builder.h"

CFG_CATEGORIES(SqlExportConfig,
     CFG_CATEGORY(SqlExport,
         CFG_ENTRY(QString, QueryTable,             QString::null)
         CFG_ENTRY(bool,    GenerateCreateTable,    false)
         CFG_ENTRY(bool,    IncludeQueryInComments, true)
     )
)

class SQLEXPORTSHARED_EXPORT SqlExport : public GenericExportPlugin
{
        Q_OBJECT

        SQLITESTUDIO_PLUGIN("sqlexport.json")

    public:
        SqlExport();

        QString getFormatName() const;
        ExportManager::StandardConfigFlags standardOptionsToEnable() const;
        CfgMain* getConfig();
        QString defaultFileExtension() const;
        QString getExportConfigFormName() const;
        bool beforeExportQueryResults(const QString& query, QList<QueryExecutor::ResultColumnPtr>& columns);
        bool exportQueryResultsRow(SqlResultsRowPtr row);
        bool afterExportQueryResults();
        bool exportTable(const QString& database, const QString& table, const QStringList& columnNames, const QString& ddl, SqliteCreateTablePtr createTable);
        bool exportVirtualTable(const QString& database, const QString& table, const QStringList& columnNames, const QString& ddl, SqliteCreateVirtualTablePtr createTable);
        bool exportTableRow(SqlResultsRowPtr data);
        bool afterExportTable();
        bool beforeExportDatabase(const QString& database);
        bool exportIndex(const QString& database, const QString& name, const QString& ddl, SqliteCreateIndexPtr createIndex);
        bool exportTrigger(const QString& database, const QString& name, const QString& ddl, SqliteCreateTriggerPtr createTrigger);
        bool exportView(const QString& database, const QString& name, const QString& ddl, SqliteCreateViewPtr createView);
        bool afterExportDatabase();
        void validateOptions();
        bool init();
        void deinit();

    private:
        bool exportTable(const QString& database, const QString& table, const QStringList& columnNames, const QString& ddl);
        void writeHeader();
        void writeBegin();
        void writeCommit();
        void writeFkDisable();
        QString getNameForObject(const QString& database, const QString& name, bool wrapped, Dialect dialect = Dialect::Sqlite3);
        QStringList rowToArgList(SqlResultsRowPtr row);

        QString theTable;
        QString columns;
        CFG_LOCAL(SqlExportConfig, cfg)
};

#endif // SQLEXPORT_H
