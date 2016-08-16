TEMPLATE = subdirs

SUBDIRS += kpk-data \
           kpk-test-console \
           kpk-data-test \
           kpk-test-quick \
           kpk-core \
    kpk-core-test

kpk-core.depends = kpk-data
kpk-core-test.depends = kpk-core

kpk-data-test.depends = kpk-data
kpk-test-console.depends = kpk-data




