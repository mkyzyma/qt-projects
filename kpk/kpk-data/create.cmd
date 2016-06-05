call createfile.cmd Name.h
call createfile.cmd Passport.h
call createfile.cmd Person.h
call createfile.cmd Member.h
odb --database pgsql --generate-schema-only --profile qt -IE:\tools\Qt\5.6\msvc2013\include\ --at-once --schema-format separate --input-name kpk Name.h Passport.h Person.h Member.h

