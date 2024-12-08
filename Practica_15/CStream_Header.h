
class CStream
{
public:
	CStream(){}
	virtual ~CStream(){}

	virtual void Open_Stream() {}
	virtual void Close_Stream() {}
	virtual void Read_Stream() {}
	virtual void Write_Stream() {}
};

class CFile : public CStream
{
private:
	std::fstream file;
	const char *filename;
public:
	CFile(const char* name){ filename = name; }
	virtual ~CFile(){}

	virtual void Open_Stream() override { printf("File Open\n"); }
	virtual void Close_Stream() override { printf("File Close\n"); }
	virtual void Read_Stream() override { printf("File Read\n"); }
	virtual void Write_Stream() override { printf("File Write\n"); }
};

class CComp : public CStream
{
private:
	const char *portName;
public:
	CComp(const char* name){ portName = name; }
	virtual ~CComp(){}

	virtual void Open_Stream() override { printf("Port Open\n"); }
	virtual void Close_Stream() override { printf("Port Close\n"); }
	virtual void Read_Stream() override { printf("Port Read\n"); }
	virtual void Write_Stream() override { printf("Port Write\n"); }
};

class CTcp : public CStream
{
private:
	const char *ipAddress;
	int port;
public:
	CTcp(const char* address, int p) { ipAddress = address; port = p; }
	virtual ~CTcp(){}

	virtual void Open_Stream() override { printf("Conexion Open\n"); }
	virtual void Close_Stream()override { printf("Conexion Close\n"); }
	virtual void Read_Stream() override { printf("Conexion Read\n"); }
	virtual void Write_Stream() override { printf("Conexion Write\n"); }
};