#ifndef CS210_CORNER_GROCER_APP_CORNER_GROCER_H_
#define CS210_CORNER_GROCER_APP_CORNER_GROCER_H_

#include <map>
#include <string>

class CornerGrocer {
 public:
  explicit CornerGrocer(const std::string& t_inputFileName);

  void loadItems();
  void createBackupFile(const std::string& t_outputFileName) const;
  int getItemFrequency(const std::string& t_itemName) const;
  void printFrequencyList() const;
  void printHistogram() const;

 private:
  std::string m_inputFileName;
  std::map<std::string, int> m_itemFrequencies;

  static std::string normalizeItemName(const std::string& t_itemName);
};

#endif  // CS210_CORNER_GROCER_APP_CORNER_GROCER_H_
