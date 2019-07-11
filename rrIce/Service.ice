module rrIce
{
    /** 自定义类型：枚举 */
    enum CustomEnum { SMT, ZL, JT };
    /** 自定义类型：结构 */
    struct CustomStruct { bool smt; bool zl; bool jt; };
    /** 自定义类型：序列 */
    sequence<byte> CustomSequence;
    /** 自定义类型：字典 */
    dictionary<string, string> CustomDictionary;

    /** 自定义异常：派生自 `Ice::UserException` */
    exception Exception { string reason; };
    /** 自定义异常：派生自 `rrIce::Exception` */
    exception RuntimeError extends Exception {};

    /** 默认标识符 */
    const string Identifier = "rrIceService";

    /** 接口 */
    interface Service
    {
        /** 内建类型回显：bool */
        idempotent bool   echoBool(bool value);
        /** 内建类型回显：byte */
        idempotent byte   echoByte(byte value);
        /** 内建类型回显：short */
        idempotent short  echoShort(short value);
        /** 内建类型回显：int */
        idempotent int    echoInt(int value);
        /** 内建类型回显：long */
        idempotent long   echoLong(long value);
        /** 内建类型回显：float */
        idempotent float  echoFloat(float value);
        /** 内建类型回显：double */
        idempotent double echoDouble(double value);
        /** 内建类型回显：string */
        idempotent string echoString(string value);

        /** 自定义类型回显：enum */
        idempotent CustomEnum       echoEnum(CustomEnum value);
        /** 自定义类型回显：struct */
        idempotent CustomStruct     echoStruct(CustomStruct value);
        /** 自定义类型回显：sequence */
        idempotent CustomSequence   echoSequence(CustomSequence value);
        /** 自定义类型回显：dictionary */
        idempotent CustomDictionary echoDictionary(CustomDictionary value);

        /** 输出标记：标记参数为输出而非输入 */
        idempotent void            getNumber(out int outValue);
        /** 可选标记：标记参数具有无效值，同一操作中可选标记必须手动指定非负序号且唯一 */
        idempotent optional(0) int optNumber(optional(1) int inValue, out optional(2) int outValue);
        /** 幂等标记：指示操作运行多次和运行一次的效果相同，该标记有益于 Ice 优化 */
        idempotent void            setNumber(int inValue);

        /** 抛出异常 */
        idempotent void throwException() throws Exception;
    }
}
