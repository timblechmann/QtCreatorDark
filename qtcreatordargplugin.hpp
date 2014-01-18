#ifndef QTCREATORDARG_HPP
#define QTCREATORDARG_HPP

#include "qtcreatordarg_global.hpp"

#include <extensionsystem/iplugin.h>

namespace QtCreatorDarg {
namespace Internal {

class QtCreatorDargPlugin : public ExtensionSystem::IPlugin
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "QtCreatorDarg.json")

public:
  QtCreatorDargPlugin();
  ~QtCreatorDargPlugin();

  bool initialize(const QStringList &arguments, QString *errorString);
  void extensionsInitialized();
  ShutdownFlag aboutToShutdown();

private slots:
  void triggerAction();
};

} // namespace Internal
} // namespace QtCreatorDarg

#endif // QTCREATORDARG_HPP

