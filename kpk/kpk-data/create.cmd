call createfile.cmd IsDeleted.h
call createfile.cmd User.h
call createfile.cmd DbObject.h
call createfile.cmd Name.h
call createfile.cmd Passport.h
call createfile.cmd Person.h
call createfile.cmd Member.h
call createfile.cmd LoanType.h
call createfile.cmd Loan.h
call createfile.cmd LoanGarantor.h
call createfile.cmd LoanOperValue.h
call createfile.cmd LoanOper.h
odb --database pgsql --generate-schema-only --profile qt/basic --profile qt/date-time -IE:\tools\Qt\5.7\msvc2013\include\ --at-once --schema-format separate --input-name kpk -q --std c++14 IsDeleted.h DbObject.h Name.h Passport.h Person.h User.h Member.h LoanType.h Loan.h LoanGarantor.h LoanOperValue.h LoanOper.h

