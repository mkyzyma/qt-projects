call createfile.cmd Name.h
call createfile.cmd Passport.h
call createfile.cmd Person.h
call createfile.cmd Member.h
call createfile.cmd LoanType.h
call createfile.cmd Loan.h
call createfile.cmd LoanOperValue.h
call createfile.cmd LoanOper.h
odb --database pgsql --generate-schema-only --profile qt/basic --profile qt/date-time -IE:\tools\Qt\5.7\msvc2013\include\ --at-once --schema-format separate --input-name kpk -q --std c++14 Name.h Passport.h Person.h Member.h LoanType.h Loan.h LoanOperValue.h LoanOper.h

