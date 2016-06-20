TEMPLATE = subdirs

SUBDIRS += kpk-data \
           kpk-test-console \
           kpk-data-test \
    kpk-test-quick

kpk-data-test.depends = kpk-data
kpk-test-console.depends = kpk-data




