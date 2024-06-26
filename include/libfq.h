#ifndef LIBFQ_H
#define LIBFQ_H

#include <stdlib.h>
#include <ibase.h>

#ifndef C_H
#define C_H


#ifndef BOOL
#define BOOL
typedef char bool;


#ifndef true
#define true    ((bool) 1)
#endif

#ifndef false
#define false   ((bool) 0)
#endif

typedef bool *BoolPtr;

#ifndef TRUE
#define TRUE    1
#endif

#ifndef FALSE
#define FALSE   0
#endif
#endif
/*
 * lengthof
 *              Number of elements in an array.
 */
#define lengthof(array) (sizeof (array) / sizeof ((array)[0]))

/*
 * endof
 *              Address of the element one past the last in an array.
 */
#define endof(array)    (&(array)[lengthof(array)])

#define HIGHBIT                         (0x80)
#define IS_HIGHBIT_SET(ch)              ((unsigned char)(ch) & HIGHBIT)


typedef unsigned char uint8;    /* == 8 bits */
typedef unsigned short uint16;  /* == 16 bits */
typedef unsigned int uint32;    /* == 32 bits */

/*
 * bitsN
 *              Unit of bitwise operation, AT LEAST N BITS IN SIZE.
 */
typedef uint8 bits8;                    /* >= 8 bits */
typedef uint16 bits16;                  /* >= 16 bits */
typedef uint32 bits32;                  /* >= 32 bits */

#endif   /* C_H */



#include "libfq-expbuffer.h"


/* Using the same loglevel constants as PostgreSQL
 * (though we don't need the server-only ones)
 *
 */
#ifndef DEBUG5
#define DEBUG5          10   /* Debugging messages, in order of decreasing detail. */
#define DEBUG4          11
#define DEBUG3          12
#define DEBUG2          13
#define DEBUG1          14
#define INFO            17   /* Messages specifically requested by user; always sent to client
                              * client regardless of client_min_messages */
#define NOTICE          18   /* Helpful messages to users about query operation;  */
#define WARNING         19   /* Unexpected but non-fatal messages. */
#define ERROR           20   /* User error - abort transaction; return to known state */
#define FATAL           21   /* Fatal error - abort process */
#define PANIC           22   /* Should never happen... */
#endif

/*
 * Return values of FQsetXXX() calls
 */
#define FQ_SET_NO_DB   -1
#define FQ_SET_ERROR    1
#define FQ_SET_SUCCESS  0

/* From ibase.h */
#ifndef SQL_TEXT
#define SQL_TEXT                           452
#define SQL_VARYING                        448
#define SQL_SHORT                          500
#define SQL_LONG                           496
#define SQL_FLOAT                          482
#define SQL_DOUBLE                         480
#define SQL_D_FLOAT                        530
#define SQL_TIMESTAMP                      510
#define SQL_BLOB                           520
#define SQL_ARRAY                          540
#define SQL_QUAD                           550
#define SQL_TYPE_TIME                      560
#define SQL_TYPE_DATE                      570
#define SQL_INT64                          580
#define SQL_TIMESTAMP_TZ_EX              32748
#define SQL_TIME_TZ_EX                   32750
#define SQL_INT128                       32752
#define SQL_TIMESTAMP_TZ                 32754
#define SQL_TIME_TZ                      32756
#define SQL_DEC16                        32760
#define SQL_DEC34                        32762
#define SQL_BOOLEAN                      32764
#define SQL_NULL                         32766
#endif

/* pseudo-type for convenience */
#define SQL_INVALID_TYPE                    -1

/* libfq customisation to indicate a column represents an RDB$DB_KEY value */
#define SQL_DB_KEY                       16384
#define FB_DB_KEY_LEN                       16

/*
 * These values are defined in "src/intl/charsets.h", but are not exported
 * publicly, so we'll maintain them here as well.
 */
#define FBENC_ASCII                           2
#define FBENC_BIG_5                           56
#define FBENC_CP943C                          68
#define FBENC_CYRL                            50
#define FBENC_DOS437                          10
#define FBENC_DOS737                          9
#define FBENC_DOS775                          15
#define FBENC_DOS850                          11
#define FBENC_DOS852                          45
#define FBENC_DOS857                          46
#define FBENC_DOS858                          16
#define FBENC_DOS860                          13
#define FBENC_DOS861                          47
#define FBENC_DOS862                          17
#define FBENC_DOS863                          14
#define FBENC_DOS864                          18
#define FBENC_DOS865                          12
#define FBENC_DOS866                          48
#define FBENC_DOS869                          49
#define FBENC_EUCJ_0208                       6
#define FBENC_GB18030                         69
#define FBENC_GBK                             67
#define FBENC_GB_2312                         57
#define FBENC_ISO8859_1                       21
#define FBENC_ISO8859_13                      40
#define FBENC_ISO8859_2                       22
#define FBENC_ISO8859_3                       23
#define FBENC_ISO8859_4                       34
#define FBENC_ISO8859_5                       35
#define FBENC_ISO8859_6                       36
#define FBENC_ISO8859_7                       37
#define FBENC_ISO8859_8                       38
#define FBENC_ISO8859_9                       39
#define FBENC_KOI8R                           63
#define FBENC_KOI8U                           64
#define FBENC_KSC_5601                        44
#define FBENC_NEXT                            19
#define FBENC_NONE                            0
#define FBENC_OCTETS                          1
#define FBENC_SJIS_0208                       5
#define FBENC_TIS620                          66
#define FBENC_UNICODE_FSS                     3
#define FBENC_UTF8                            4
#define FBENC_WIN1250                         51
#define FBENC_WIN1251                         52
#define FBENC_WIN1252                         53
#define FBENC_WIN1253                         54
#define FBENC_WIN1254                         55
#define FBENC_WIN1255                         58
#define FBENC_WIN1256                         59
#define FBENC_WIN1257                         60
#define FBENC_WIN1258                         65

/* pseudo-encoding  for convenience */
#define FBENC_UNKNOWN                         -1

#define BLOB_SEGMENT_LEN 80

/*
 * Maximum number of connection parameters supported by
 * FQconnectdbParams()
 */
#define FBCONN_MAX_PARAMS 7

typedef enum
{
	CONNECTION_OK = 0,
	CONNECTION_BAD
} FBconnStatusType;


typedef enum {
    FBRES_NO_ACTION = 0,
	FBRES_EMPTY_QUERY,
	FBRES_COMMAND_OK,
	FBRES_TUPLES_OK,
	FBRES_TRANSACTION_START,
	FBRES_TRANSACTION_COMMIT,
	FBRES_TRANSACTION_ROLLBACK,
	FBRES_BAD_RESPONSE,
	FBRES_NONFATAL_ERROR,
	FBRES_FATAL_ERROR
} FQexecStatusType;

typedef enum {
	FB_DIAG_OTHER = 0,
	FB_DIAG_MESSAGE_TYPE,
	FB_DIAG_MESSAGE_PRIMARY,
	FB_DIAG_MESSAGE_DETAIL,
	FB_DIAG_DEBUG  /* debugging info, not usually displayed */
} FQdiagType;


typedef enum {
	TRANS_OK,
	TRANS_ERROR
} FQtransactionStatusType;


typedef struct FBconn {
	isc_db_handle  db;
	isc_tr_handle  trans;
	isc_tr_handle  trans_internal;		  /* transaction handle for atomic internal operations */
	char		  *db_path;
	char		  *uname;
	char		  *upass;
	bool		   autocommit;
	bool		   in_user_transaction;	  /* set when explicit SET TRANSACTION was executed */
	char		  *dpb_buffer;
	short		   dpb_length;
	ISC_STATUS	  *status;
	char		  *engine_version;		  /* Firebird version as reported by RDB$GET_CONTEXT() */
	int			   engine_version_number; /* integer representation of Firebird version */
	short		   client_min_messages;
	short		   client_encoding_id;	  /* corresponds to MON$ATTACHMENTS.MON$CHARACTER_SET_ID */
	char		  *client_encoding;		  /* client encoding, default UTF8 */
	bool		   time_zone_names;		  /* whether to emit time zones as names or numeric offsets */
	bool		   isql_values;			  /* whether to mimic ISQL-style value output */
	bool		   get_dsp_len;			  /* calculate display length in single characters of each datum */
	char		  *errMsg;		  		  /* most recently generated error message */
} FBconn;



/* Stores metadata for a tuple attribute (column) */
typedef struct FQresTupleAttDesc
{
    char  *desc;				/* column name */
    short  desc_len;			/* length of column name */
    short  desc_dsplen;			/* display length of column name in single characters */
    char  *alias;				/* column alias, if provided */
    short  alias_len;			/* length of column alias */
    short  alias_dsplen;		/* display length of alias name in single characters */
    char  *relname;				/* table name from whence the column is derived */
    short  relname_len;			/* length of table name  */
    int	   att_max_len;			/* max length of value in column */
    int    att_max_line_len;	/* max length of line in text column */
    short  type;				/* datatype */
    bool   has_null;			/* indicates if resultset contains at least one NULL */
} FQresTupleAttDesc;


/* Stores value and metadata for an individual tuple attribute (row column) */
typedef struct FQresTupleAtt
{
    char *value;        /* pointer to the tuple's value expressed as a cstring */
    int   len;          /* length in bytes */
    int   dsplen;       /* Display length in single-width characters */
    int   dsplen_line;  /* Display length in single-width characters of the longest line
                         * (if value is a text field with multiple lines) */
    int   lines;        /* Number of lines (if value is a text field with multiple lines) */
    bool  has_null;
} FQresTupleAtt;


/* Stores metadata for a tuple (row) */
typedef struct FQresTuple
{
    FQresTupleAtt     **values;
    int                 position;
    int                 max_lines;
    struct FQresTuple  *next;
} FQresTuple;


/* Typedef for message-field list entries */
typedef struct fbMessageField
{
	struct fbMessageField *prev;	/* list link */
	struct fbMessageField *next;	/* list link */
	FQdiagType			   code;	/* field code */
	char				  *value;	/* field value */
} FBMessageField;


/* Initialised with _FQinitResult() */
typedef struct FBresult
{
	XSQLDA *sqlda_out;				/* Pointer to a Firebird XSQLDA structure used to hold output tuple information. */
	XSQLDA *sqlda_in;				/* Pointer to a Firebird XSQLDA structure used to hold data for prepared statements.
									 * NOTE: the XSQLDA pointers are only used during query execution and will be
									 * freed once execution has completed; see _FQexecClearResult().
									 */
	isc_stmt_handle stmt_handle;
	ISC_LONG statement_type;
	FQexecStatusType resultStatus;
	int ntups;						/* The number of rows (tuples) returned by a query.
									 * Will be -1 until a valid query is executed. */
	int ncols;						/* The number of columns in the result tuples.
									 * Will be -1 until a valid query is executed. */

	struct FQresTupleAttDesc **header;
	struct FQresTuple **tuples;		/* Array of pointers to returned tuples */

	struct FQresTuple *tuple_first; /* Pointer to first returned tuple */
	struct FQresTuple *tuple_last;	/* Pointer to last returned tuple */

	/*
	 * Error information (all NULL if not an error result).	 errMsg is the
	 * "overall" error message returned by FQresultErrorMessage.  If we have
	 * per-field info then it is stored in a linked list.
	 */
	char	   *errMsg;			/* error message, or NULL if no error */
	FBMessageField *errFields;	/* message broken into fields */
	long	   fbSQLCODE;		/* Firebird SQL code */
	int	   	   errLine;
	int	   	   errCol;
} FBresult;

extern char *const fbresStatus[];


/*
 * =====================================
 * Database Connection Control Functions
 * =====================================
 */

extern FBconn *FQconnect(const char *db_path, const char *uname, const char *upass);

extern FBconn *FQconnectdbParams(const char * const *keywords, const char * const *values);

extern FBconn *FQreconnect(FBconn *conn);

extern void FQfinish(FBconn *conn);

extern int FQsetTimeZoneNames(FBconn *conn, bool time_zone_names);
extern int FQsetIsqlValues(FBconn *conn, bool isql_values);
extern int FQsetClientMinMessages(FBconn *conn, int log_level);
extern int FQsetClientMinMessagesString(FBconn *conn, const char *log_level);

/*
 * ====================================
 * Database Connection Status Functions
 * ====================================
 */

extern FBconnStatusType FQstatus(FBconn *conn);

extern const char *FQparameterStatus(FBconn *conn, const char *paramName);

extern const char *FQdb_path(const FBconn *conn);

extern const char *FQuname(const FBconn *conn);

extern const char *FQupass(const FBconn *conn);

extern int FQserverVersion(FBconn *conn);

extern char *FQserverVersionString(FBconn *conn);

extern int FQclientEncodingId(FBconn *conn);

/*
 * ===========================
 * Command Execution Functions
 * ===========================
 */

extern FBresult *FQexec(FBconn *conn, const char *stmt);


extern FBresult *
FQexecParams(FBconn *conn,
			 const char *stmt,
			 int nParams,
			 const int *paramTypes,
			 const char * const *paramValues,
			 const int *paramLengths,
			 const int *paramFormats,
			 int resultFormat);

extern FBresult *
FQprepare(FBconn *conn,
		  const char *stmt,
		  int nParams,
		  const int *paramTypes);

extern FBresult *
FQexecPrepared(FBconn *conn,
			   FBresult *result,
			   int nParams,
			   const char * const *paramValues,
			   const int *paramLengths,
			   const int *paramFormats,
			   int resultFormat);

extern void
FQdeallocatePrepared(FBconn *conn, FBresult *result);

extern FBresult *FQexecTransaction(FBconn *conn, const char *stmt);

/*
 * =========================
 * Result handling functions
 * =========================
 */

extern FQexecStatusType
FQresultStatus(const FBresult *res);

extern char *
FQresStatus(FQexecStatusType status);

extern int
FQsqlCode(const FBresult *res);

extern int
FQntuples(const FBresult *res);

extern int
FQnfields(const FBresult *res);

extern int
FQgetlines(const FBresult *res,
		   int row_number,
		   int column_number);

extern char *
FQgetvalue(const FBresult *res,
           int row_number,
           int column_number);

extern int
FQgetisnull(const FBresult *res,
            int row_number,
            int column_number);

extern bool
FQfhasNull(const FBresult *res, int column_number);

extern int
FQfmaxwidth(const FBresult *res, int column_number);

extern char *
FQfname(const FBresult *res, int column_number);

extern short
FQfformat(const FBresult *res, int column_number);

extern short
FQftype(const FBresult *res, int column_number);

extern void
FQsetGetdsplen(FBconn *conn, bool get_dsp_len);

extern int
FQgetlength(const FBresult *res,
            int row_number,
            int column_number);

extern int
FQgetdsplen(const FBresult *res,
            int row_number,
            int column_number);

extern int
FQrgetlines(const FBresult *res,
		   int row_number);

extern char *
FQformatDbKey(const FBresult *res,
              int row_number,
              int column_number);

extern void
FQclear(FBresult *res);



/*
 * ==============================
 * Transaction handling functions
 * ==============================
 */

extern void
FQsetAutocommit(FBconn *conn, bool autocommit);

extern FQtransactionStatusType
FQstartTransaction(FBconn *conn);

extern FQtransactionStatusType
FQcommitTransaction(FBconn *conn);

extern FQtransactionStatusType
FQrollbackTransaction(FBconn *conn);

extern bool
FQisActiveTransaction(FBconn *conn);


/*
 * ========================
 * Error handling functions
 * ========================
 */

extern char *
FQerrorMessage(const FBconn *conn);

extern char *
FQresultErrorMessage(const FBresult *res);

extern char *
FQresultErrorField(const FBresult *res, FQdiagType fieldcode);

extern char *
FQresultErrorFieldsAsString(const FBresult *res, char *prefix);

/*
 * ===========================
 * libfq information functions
 * ===========================
 */
extern int FQlibVersion(void);

extern const char *FQlibVersionString(void);

extern int FQfirebirdApiVersion(void);

/*
 * =======================
 * Miscellaneous functions
 * =======================
 */

extern char *
FQplanStatement(FBconn *conn, const char *stmt);

extern char *
FQexplainStatement(FBconn *conn, const char *stmt);

extern void
FQlog(FBconn *conn, short loglevel, const char *msg, ...);


/* handling for character/encoding */

extern int FQmblen(const char *s, short encoding_id);

extern int FQdsplen(const unsigned char *s, short encoding_id);

extern int FQdspstrlen(const char *s, short encoding_id);

#endif   /* LIBFQ_H */
