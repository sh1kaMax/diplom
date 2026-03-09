#include <string.h>
#include <stdexcept>

class data {
public:
  std::string getType() const { return std::string("class data"); }
  int getData() const { return 1; }
};

int getData(const data* pData, const data* pBackupData)
{
  if (pData)
  {
    return pData->getData();
  }
  else if (pBackupData)
  {
    return pBackupData->getData();
  }
  else
    throw std::runtime_error("Unhandled data type " + pData->getType()); // FLAW
}

int main(int argc, char* argv[]) {
  try {
    int data = getData(0, 0);
    printf("data %d\n", data);
  } catch(std::exception& e) {
    printf("%s\n", e.what());
  }

  return 0;
}
