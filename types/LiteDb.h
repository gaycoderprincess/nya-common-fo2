enum eDBValueType {
	DBVALUE_CHAR = 1,
	DBVALUE_STRING = 2,
	DBVALUE_BOOL = 5,
	DBVALUE_INT = 6,
	DBVALUE_FLOAT = 7,
	DBVALUE_RGBA = 8,
	DBVALUE_VECTOR2 = 9,
	DBVALUE_VECTOR3 = 10,
	DBVALUE_VECTOR4 = 11,
	DBVALUE_NODE = 12,
	DBVALUE_MAX_COUNT
};

class LiteDb {
public:

	struct tMappedValue {
		const char* name;
		uint32_t typeFlags; // usually 0x40X, last byte is the type, arrays seem to be 0x100800X
		void* valuePtr;
	};

	static inline auto& gNodes = *(LiteDb**)0x8DA728;

	virtual void _vf0() = 0;
	virtual void AddMappedTable(const char* name, tMappedValue* values, int flags, int a4) = 0; // flags and a4 usually 2 0
	virtual LiteDb* GetTable_2(const char* name) = 0; // this jumps to GetTable if name isn't null
	virtual void _vf3() = 0;
	virtual const char* GetName() = 0;
	virtual void _vf5() = 0;
	virtual int GetNumChildren() = 0;
	virtual int GetNumChildren_2() = 0; // this jumps to GetNumChildren
	virtual LiteDb* GetParent() = 0;
	virtual void _vf9() = 0;
	virtual LiteDb* GetTable(const char* name) = 0;
	virtual LiteDb* GetChildByIndex(int index) = 0;
	virtual void GetFullPath(char* out) = 0;
	virtual int GetNumProperties() = 0;
	virtual const char* GetPropertyNameByIndex(int index) = 0;
	virtual bool DoesPropertyExist(const char* name) = 0;
	virtual int GetPropertyType(const char* name) = 0;
	virtual void _vf17() = 0;
	virtual void _vf18() = 0;
	virtual int GetPropertyArraySize(const char* name) = 0;
	virtual void _vf20() = 0;
	virtual void _vf21() = 0;
	virtual void _vf22() = 0;
	virtual void _vf23() = 0;
	virtual void _vf24() = 0;
	virtual void _vf25() = 0;
	virtual void _vf26() = 0;
	virtual void _vf27() = 0;
	virtual void _vf28() = 0;
	virtual void _vf29() = 0;
	virtual void _vf30() = 0;
	virtual void _vf31() = 0;
	virtual void _vf32() = 0;
	virtual void _vf33() = 0;
	virtual void _vf34() = 0;
	virtual void* GetPropertyPointer(const char* name) = 0;
	virtual int GetPropertyAsBool(const char* name, int offset) = 0;
	virtual int GetPropertyAsInt(const char* name, int offset) = 0;
	virtual char GetPropertyAsChar(const char* name, int offset) = 0;
	virtual float GetPropertyAsFloat(const char* name, int offset) = 0;
	virtual uint32_t GetPropertyAsRGBA(const char* name, int offset) = 0;
	virtual void* GetPropertyAsVector2(void* out, const char* name, int offset) = 0;
	virtual void* GetPropertyAsVector3(void* out, const char* name, int offset) = 0;
	virtual void* GetPropertyAsVector4(void* out, const char* name, int offset) = 0;
	virtual char* GetPropertyAsNodePath(char* out, const char* name, int offset) = 0;
	virtual LiteDb* GetPropertyAsNode(const char* name, int offset) = 0;
	virtual const char* GetPropertyAsString(const char* name) = 0;
};
auto GetLiteDB = (LiteDb*(*)())0x54C960;