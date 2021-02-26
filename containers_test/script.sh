R='\u001b[31m'
G='\u001b[32m'
B='\u001b[33m'
W='\u001b[0m'

STD_BIN='bin/test_std/'
FT_BIN='bin/test_ft/'


VEC='vector/'
LIST='list/'


echo -e "TEST VECTOR\n"

<<C
diff <(${FT_BIN}${VEC}constructor) <(${STD_BIN}${VEC}constructor)
if [ ! $? -ne 0 ];
then
    echo -e "${G}CONSTRUCTOR : OK${W}"
else
    echo -e "${R}CONSTRUCTOR : KO${W}"
fi


diff <(${FT_BIN}${VEC}reserve) <(${STD_BIN}${VEC}reserve)
if [ ! $? -ne 0 ];
then
    echo -e "${G}RESERVE : OK${W}"
else
    echo -e "${R}RESERVE : KO${W}"
fi


diff <(${FT_BIN}${VEC}resize) <(${STD_BIN}${VEC}resize)
if [ ! $? -ne 0 ];
then
    echo -e "${G}RESIZE : OK${W}"
else
    echo -e "${R}RESIZE : KO${W}"
fi

diff <(${FT_BIN}${VEC}assign) <(${STD_BIN}${VEC}assign)
if [ ! $? -ne 0 ];
then
    echo -e "${G}ASSIGN : OK${W}"
else
    echo -e "${R}ASSIGN : KO${W}"
fi


diff <(${FT_BIN}${VEC}push_pop) <(${STD_BIN}${VEC}push_pop)
if [ ! $? -ne 0 ];
then
    echo -e "${G}PUSH POP : OK${W}"
else
    echo -e "${R}PUSH POP : KO${W}"
fi


diff <(${FT_BIN}${VEC}swap) <(${STD_BIN}${VEC}swap)
if [ ! $? -ne 0 ];
then
    echo -e "${G}SWAP : OK${W}"
else
    echo -e "${R}SWAP : KO${W}"
fi


diff <(${FT_BIN}${VEC}clear) <(${STD_BIN}${VEC}clear)
if [ ! $? -ne 0 ];
then
    echo -e "${G}CLEAR : OK${W}"
else
    echo -e "${R}CLEAR : KO${W}"
fi


diff <(${FT_BIN}${VEC}insert) <(${STD_BIN}${VEC}insert)
if [ ! $? -ne 0 ];
then
    echo -e "${G}INSERT : OK${W}"
else
    echo -e "${R}INSERT : KO${W}"
fi


diff <(${FT_BIN}${VEC}erase) <(${STD_BIN}${VEC}erase)
if [ ! $? -ne 0 ];
then
    echo -e "${G}ERASE : OK${W}"
else
    echo -e "${R}ERASE : KO${W}"
fi


diff <(${FT_BIN}${VEC}operator) <(${STD_BIN}${VEC}operator)
if [ ! $? -ne 0 ];
then
    echo -e "${G}RELATIONAL OPERATOR : OK${W}"
else
    echo -e "${R}RELATIONAL OPERATOR : KO${W}"
fi


diff <(${FT_BIN}${VEC}iterator) <(${STD_BIN}${VEC}iterator)
if [ ! $? -ne 0 ];
then
    echo -e "${G}ITERATOR: OK${W}"
else
    echo -e "${R}ITERATOR : KO${W}"
fi

C


<<C

echo -e "TEST LIST\n"

<<C

diff <(${FT_BIN}${LIST}default_constructor) <(${STD_BIN}${LIST}default_constructor)
if [ ! $? -ne 0 ];
then
    echo -e "${G}DEFAULT CONSTRUCTOR : OK${W}"
else
    echo -e "${R}DEFAULT CONSTRUCTOR : KO${W}"
fi

diff <(${FT_BIN}${LIST}constructor2) <(${STD_BIN}${LIST}constructor2)
if [ ! $? -ne 0 ];
then
    echo -e "${G}CONSTRUCTOR 2 : OK${W}"
else
    echo -e "${R}CONSTRUCTOR 2 : KO${W}"
fi


diff <(${FT_BIN}${LIST}push_pop_front) <(${STD_BIN}${LIST}push_pop_front)
if [ ! $? -ne 0 ];
then
    echo -e "${G}PUSH POP FRONT : OK${W}"
else
    echo -e "${R}PUSH POP FRONT : KO${W}"
fi


diff <(${FT_BIN}${LIST}push_pop_back) <(${STD_BIN}${LIST}push_pop_back)
if [ ! $? -ne 0 ];
then
    echo -e "${G}PUSH POP BACK : OK${W}"
else
    echo -e "${R}PUSH POP BACK : KO${W}"
fi


diff <(${FT_BIN}${LIST}iterator) <(${STD_BIN}${LIST}iterator)
if [ ! $? -ne 0 ];
then
    echo -e "${G}ITERATOR : OK${W}"
else
    echo -e "${R}ITERATOR : KO${W}"
fi


diff <(${FT_BIN}${LIST}constructor3) <(${STD_BIN}${LIST}constructor3)
if [ ! $? -ne 0 ];
then
    echo -e "${G}CONSTRUCTOR 3 : OK${W}"
else
    echo -e "${R}CONSTRUCTOR 3 : KO${W}"
fi

diff <(${FT_BIN}${LIST}assign) <(${STD_BIN}${LIST}assign)
if [ ! $? -ne 0 ];
then
    echo -e "${G}ASSIGN : OK${W}"
else
    echo -e "${R}ASSIGN : KO${W}"
fi

diff <(${FT_BIN}${LIST}resize) <(${STD_BIN}${LIST}resize)
if [ ! $? -ne 0 ];
then
    echo -e "${G}RESIZE : OK${W}"
else
    echo -e "${R}RESIZE : KO${W}"
fi


diff <(${FT_BIN}${LIST}clear) <(${STD_BIN}${LIST}clear)
if [ ! $? -ne 0 ];
then
    echo -e "${G}CLEAR : OK${W}"
else
    echo -e "${R}CLEAR : KO${W}"
fi


diff <(${FT_BIN}${LIST}swap) <(${STD_BIN}${LIST}swap)
if [ ! $? -ne 0 ];
then
    echo -e "${G}SWAP : OK${W}"
else
    echo -e "${R}SWAP : KO${W}"
fi


diff <(${FT_BIN}${LIST}erase) <(${STD_BIN}${LIST}erase)
if [ ! $? -ne 0 ];
then
    echo -e "${G}ERASE : OK${W}"
else
    echo -e "${R}ERASE : KO${W}"
fi


diff <(${FT_BIN}${LIST}insert) <(${STD_BIN}${LIST}insert)
if [ ! $? -ne 0 ];
then
    echo -e "${G}INSERT : OK${W}"
else
    echo -e "${R}INSERT : KO${W}"
fi


diff <(${FT_BIN}${LIST}splice) <(${STD_BIN}${LIST}splice)
if [ ! $? -ne 0 ];
then
    echo -e "${G}SPLICE : OK${W}"
else
    echo -e "${R}SPLICE : KO${W}"
fi



diff <(${FT_BIN}${LIST}remove) <(${STD_BIN}${LIST}remove)
if [ ! $? -ne 0 ];
then
    echo -e "${G}REMOVE : OK${W}"
else
    echo -e "${R}REMOVE : KO${W}"
fi


diff <(${FT_BIN}${LIST}remove_if) <(${STD_BIN}${LIST}remove_if)
if [ ! $? -ne 0 ];
then
    echo -e "${G}REMOVE_IF : OK${W}"
else
    echo -e "${R}REMOVE_IF : KO${W}"
fi

diff <(${FT_BIN}${LIST}unique) <(${STD_BIN}${LIST}unique)
if [ ! $? -ne 0 ];
then
    echo -e "${G}UNIQUE : OK${W}"
else
    echo -e "${R}UNIQUE : KO${W}"
fi

diff <(${FT_BIN}${LIST}merge) <(${STD_BIN}${LIST}merge)
if [ ! $? -ne 0 ];
then
    echo -e "${G}MERGE : OK${W}"
else
    echo -e "${R}MERGE : KO${W}"
fi


diff <(${FT_BIN}${LIST}sort) <(${STD_BIN}${LIST}sort)
if [ ! $? -ne 0 ];
then
    echo -e "${G}SORT : OK${W}"
else
    echo -e "${R}SORT : KO${W}"
fi

diff <(${FT_BIN}${LIST}sort) <(${STD_BIN}${LIST}sort)
if [ ! $? -ne 0 ];
then
    echo -e "${G}SORT : OK${W}"
else
    echo -e "${R}SORT : KO${W}"
fi


diff <(${FT_BIN}${LIST}reverse) <(${STD_BIN}${LIST}reverse)
if [ ! $? -ne 0 ];
then
    echo -e "${G}REVERSE : OK${W}"
else
    echo -e "${R}REVERSE : KO${W}"
fi

diff <(${FT_BIN}${LIST}operator) <(${STD_BIN}${LIST}operator)
if [ ! $? -ne 0 ];
then
    echo -e "${G}OPERATOR : OK${W}"
else
    echo -e "${R}OPERATOR : KO${W}"
fi

C