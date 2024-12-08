class CImage
{
public:
	CImage() {}
	~CImage() {}
	enum class EType
	{
		IMAGE,
		JPG,
		PNG
	};

	EType m_eType = EType::IMAGE;
};

class CJpg : public CImage
{
public:
	CJpg() { m_eType = EType::JPG; }
	~CJpg() {}
};

class CPng : public CImage
{
public:
	CPng() { m_eType = EType::PNG; }
	~CPng() {}
	void DeleteAlphaChanel()
	{
		printf("Canal Alpha de PNG Borrado\n");
	};

};
