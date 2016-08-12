include("cfg.pri")

DEPENDPATH += $$tools/qdecimal/
INCLUDEPATH += $$tools/qdecimal/decnumber $$tools/qdecimal/src
LIBS += -L$$tools/qdecimal/lib -lqdecimal -ldecnumber




