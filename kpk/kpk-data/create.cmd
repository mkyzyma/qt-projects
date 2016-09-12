call createfile.cmd IsDeleted.h
call createfile.cmd User.h
call createfile.cmd DbObject.h
call createfile.cmd Name.h
call createfile.cmd Passport.h
call createfile.cmd Person.h
call createfile.cmd Member.h
call createfile.cmd MemberInfo.h
call createfile.cmd LoanType.h
call createfile.cmd LoanState.h
call createfile.cmd Loan.h
call createfile.cmd LoanGarantor.h
call createfile.cmd Bank.h
call createfile.cmd Payment.h
call createfile.cmd LoanPaymentValue.h
call createfile.cmd LoanPayment.h
call createfile.cmd DecTest.h
odb --database pgsql --generate-schema-only --profile qt/basic --profile qt/date-time ^
-IE:\tools\Qt\5.7\msvc2013\include\ -IE:\tools\qdecimal\decnumber -IE:\tools\qdecimal\src ^
--at-once --schema-format separate --input-name kpk -q --std c++14 ^
--hxx-prologue "#include \"traits-pgsql.h\"" ^
IsDeleted.h DbObject.h Name.h Passport.h Person.h User.h ^
Member.h MemberInfo.h LoanType.h LoanState.h Loan.h LoanGarantor.h Bank.h Payment.h ^
LoanPaymentValue.h LoanPayment.h DecTest.h

