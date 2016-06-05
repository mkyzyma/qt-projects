CONFIG += c++14

win32: tools = E:/tools
else:unix{
    QMAKE_CXXFLAGS_WARN_ON += -Wno-reorder
    QMAKE_CXXFLAGS_WARN_ON += -Wno-unknown-pragmas

    tools = ~/tools
}
odb_ver = 2.4.0
odb_dll_suff = -2.4-vc12

odb = $${tools}/odb/libodb
libodb = $$odb-$$odb_ver
libodb_pgsql = $$odb-pgsql-$$odb_ver
libodb_qt = $$odb-qt-$$odb_ver

qt_path = $${tools}/QT/5.6/msvc2013
qt_include = $$qt_path/include

pg_path = $${tools}/PostgreSQL/9.5.
pg_include = $${pg_path}32/include

INCLUDEPATH += $$libodb $$libodb_pgsql $$libodb_qt $$qt_include $$pg_include
DEPENDPATH += $$INCLUDEPATH

win32{
    !contains(QMAKE_TARGET.arch, x86_64) {
        odb_lib = lib
        odb_bin = bin
        qt_lib = /lib
        qt_bin = /bin
        pg_path = $${pg_path}32
    } else {
        odb_lib = lib64
        odb_bin = bin64
        qt_lib = _64/lib
        qt_bin = _64/bin
        pg_path = $${pg_path}64
    }

    cfg_name = 'release'

    CONFIG(debug, debug|release){
        cfg = -d
        cfg_name = 'debug'
    }

    LIBS += $${libodb}/$${odb_lib}/odb$${cfg}.lib \
            $${libodb_pgsql}/$${odb_lib}/odb-pgsql$${cfg}.lib \
            $${libodb_qt}/$${odb_lib}/odb-qt$${cfg}.lib \
            -L$${qt_path}$${qt_lib}/ -lQt5Core \
            $${pg_path}/lib/libpq.lib

    EXTRA_BINFILES += $${libodb}/$${odb_bin}/odb$${cfg}$${odb_dll_suff}.dll \
                      $${libodb_pgsql}/$${odb_bin}/odb-pgsql$${cfg}$${odb_dll_suff}.dll \
                      $${libodb_qt}/$${odb_bin}/odb-qt5$${cfg}$${odb_dll_suff}.dll \
                      $${qt_path}$${qt_bin}/Qt5Core.dll \
                      $${pg_path}/bin/libpq.dll \
                      $${pg_path}/bin/libeay32.dll \
                      $${pg_path}/bin/ssleay32.dll \
                      $${pg_path}/bin/libintl-8.dll \
                      $${pg_path}/bin/libiconv-2.dll \

    EXTRA_BINFILES_WIN = $${EXTRA_BINFILES}
    EXTRA_BINFILES_WIN ~= s,/,\\,g

    DESTDIR_WIN = $${OUT_PWD}/$$cfg_name
    DESTDIR_WIN ~= s,/,\\,g

    for(FILE,EXTRA_BINFILES_WIN){
        QMAKE_POST_LINK +=$$quote(cmd /c copy /y $${FILE} $${DESTDIR_WIN}$$escape_expand(\n\t))
    }
}
unix{
    LIBS += -lodb \
            -lodb-pgsql \
            -lodb-qt \
            -lQt5Core \
            -lpq
}
#message($$PWD)
#message($$QMAKE_POST_LINK)

