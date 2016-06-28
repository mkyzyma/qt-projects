CONFIG += c++14



win32{
    tools = E:/tools
}
else:unix{
    QMAKE_CXXFLAGS_WARN_ON += -Wno-reorder
    QMAKE_CXXFLAGS_WARN_ON += -Wno-unknown-pragmas
    tools = ~/tools
}
