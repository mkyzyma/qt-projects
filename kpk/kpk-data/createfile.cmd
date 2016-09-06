odb -d pgsql --generate-session --profile qt/basic --profile qt/date-time ^
-IE:\tools\Qt\5.7\msvc2013\include\ -IE:\tools\qdecimal\decnumber -IE:\tools\qdecimal\src ^
--hxx-prologue "#include \"traits-pgsql.h\"" ^
-q --std c++14 %1
