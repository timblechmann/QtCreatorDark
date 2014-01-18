#include "qtcreatordargplugin.hpp"
#include "qtcreatordargconstants.hpp"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>

#include <QApplication>
#include <QStyleFactory>

#include <QtPlugin>

using namespace QtCreatorDarg::Internal;

QtCreatorDargPlugin::QtCreatorDargPlugin()
{
  // Create your members

//  QApplication::setStyle(QStyleFactory::create(QString::fromAscii("Fusion")));
  QPalette p;
  p = qApp->palette();
  p.setColor(QPalette::Window, QColor(53,53,53));
  p.setColor(QPalette::Button, QColor(53,53,53));
  p.setColor(QPalette::Highlight, QColor(142,45,197));
  p.setColor(QPalette::ButtonText, QColor(255,255,255));
  p.setColor(QPalette::Background, QColor(25,25,25));
  p.setColor(QPalette::Text, QColor(255,255,255));
  p.setColor(QPalette::WindowText, QColor(255,255,255));
  p.setColor(QPalette::Base, QColor(15,15,15));
  qApp->setPalette(p);
}

QtCreatorDargPlugin::~QtCreatorDargPlugin()
{
  // Unregister objects from the plugin manager's object pool
  // Delete members
}

bool QtCreatorDargPlugin::initialize(const QStringList &arguments, QString *errorString)
{
  // Register objects in the plugin manager's object pool
  // Load settings
  // Add actions to menus
  // Connect to other plugins' signals
  // In the initialize function, a plugin can be sure that the plugins it
  // depends on have initialized their members.

  Q_UNUSED(arguments)
  Q_UNUSED(errorString)

  QAction *action = new QAction(tr("QtCreatorDarg action"), this);
  Core::Command *cmd = Core::ActionManager::registerAction(action, Constants::ACTION_ID,
                                                           Core::Context(Core::Constants::C_GLOBAL));
  cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+Meta+A")));
  connect(action, SIGNAL(triggered()), this, SLOT(triggerAction()));

  Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
  menu->menu()->setTitle(tr("QtCreatorDarg"));
  menu->addAction(cmd);
  Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

  return true;
}

void QtCreatorDargPlugin::extensionsInitialized()
{
  // Retrieve objects from the plugin manager's object pool
  // In the extensionsInitialized function, a plugin can be sure that all
  // plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag QtCreatorDargPlugin::aboutToShutdown()
{
  // Save settings
  // Disconnect from signals that are not needed during shutdown
  // Hide UI (if you add UI that is not in the main window directly)
  return SynchronousShutdown;
}

void QtCreatorDargPlugin::triggerAction()
{
  QMessageBox::information(Core::ICore::mainWindow(),
                           tr("Action triggered"),
                           tr("This is an action from QtCreatorDarg."));
}

Q_EXPORT_PLUGIN2(QtCreatorDarg, QtCreatorDargPlugin)

