# Instalación y Configuración de Git

Esta guía te ayudará a instalar y configurar Git en Windows, Linux y macOS.

---

## Windows

### Opción 1: Instalador oficial (Recomendado)

1. **Descargar Git:**
   - Visita: https://git-scm.com/download/win
   - Descarga el instalador para Windows (64-bit o 32-bit según tu sistema)

2. **Instalar:**
   - Ejecuta el archivo `.exe` descargado
   - Sigue el asistente de instalación (puedes dejar las opciones por defecto)
   - Recomendado: Selecciona "Git Bash Here" y "Git GUI Here" en el menú contextual

3. **Verificar instalación:**
   ```bash
   git --version
   ```

### Opción 2: Usando Chocolatey

Si tienes Chocolatey instalado:
```bash
choco install git
```

### Opción 3: Usando winget (Windows 10/11)

```bash
winget install --id Git.Git -e --source winget
```

### Acceder a Git en Windows

- **Git Bash**: Terminal estilo Unix (recomendado)
- **Git CMD**: Línea de comandos de Windows
- **PowerShell**: También funciona con Git instalado

---

## Linux

### Ubuntu/Debian

```bash
# Actualizar lista de paquetes
sudo apt update

# Instalar Git
sudo apt install git

# Verificar instalación
git --version
```

### Fedora/RHEL/CentOS

```bash
# Instalar Git
sudo dnf install git
# O en versiones antiguas:
sudo yum install git

# Verificar instalación
git --version
```

### Arch Linux

```bash
# Instalar Git
sudo pacman -S git

# Verificar instalación
git --version
```

### openSUSE

```bash
# Instalar Git
sudo zypper install git

# Verificar instalación
git --version
```

### Compilar desde el código fuente

Si necesitas la última versión o tu distribución no tiene Git:

```bash
# Instalar dependencias
sudo apt install libcurl4-openssl-dev libexpat1-dev gettext libz-dev libssl-dev

# Descargar y compilar
wget https://github.com/git/git/archive/v2.42.0.tar.gz
tar -xzf v2.42.0.tar.gz
cd git-2.42.0
make prefix=/usr/local all
sudo make prefix=/usr/local install
```

---

## macOS

### Opción 1: Xcode Command Line Tools (Recomendado)

```bash
# Instalar Git (incluido en Xcode Command Line Tools)
xcode-select --install
```

Si aparece un diálogo, haz clic en "Install" y espera a que termine.

### Opción 2: Homebrew (Recomendado para usuarios avanzados)

```bash
# Instalar Homebrew si no lo tienes
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Instalar Git
brew install git

# Verificar instalación
git --version
```

### Opción 3: Instalador oficial

1. Visita: https://git-scm.com/download/mac
2. Descarga el instalador `.dmg`
3. Ejecuta el instalador y sigue las instrucciones

### Verificar instalación en macOS

```bash
git --version
```

---

## Configuración Inicial (Todos los sistemas)

Después de instalar Git, configura tu identidad:

### Configurar nombre y email

```bash
# Configuración global (para todos los repositorios)
git config --global user.name "Tu Nombre"
git config --global user.email "tu.email@ejemplo.com"

# Verificar configuración
git config --list
```

### Configuración adicional útil

```bash
# Editor por defecto (opcional)
git config --global core.editor "code --wait"  # VS Code
git config --global core.editor "nano"        # Nano
git config --global core.editor "vim"         # Vim

# Nombre de la rama por defecto
git config --global init.defaultBranch main

# Colores en la terminal
git config --global color.ui auto

# Ver todas las configuraciones
git config --list --show-origin
```

### Configuración por repositorio (local)

Si quieres una configuración diferente para un proyecto específico:

```bash
cd /ruta/al/proyecto
git config user.name "Nombre para este proyecto"
git config user.email "email@proyecto.com"
```

---

## Verificar la Instalación

### Comando básico

```bash
git --version
```

Deberías ver algo como: `git version 2.42.0` (o la versión que instalaste)

### Verificar configuración

```bash
# Ver todas las configuraciones
git config --list

# Ver configuración específica
git config user.name
git config user.email
```

---

## Primeros Pasos

### 1. Inicializar un repositorio

```bash
# Crear un nuevo repositorio
mkdir mi-proyecto
cd mi-proyecto
git init
```

### 2. Clonar un repositorio existente

```bash
# Clonar desde GitHub, GitLab, etc.
git clone https://github.com/usuario/repositorio.git
```

### 3. Hacer tu primer commit

```bash
# Crear un archivo
echo "# Mi Proyecto" > README.md

# Agregar al staging
git add README.md

# Hacer commit
git commit -m "Primer commit: agregar README"
```

---

## Solución de Problemas Comunes

### Git no se reconoce como comando

**Windows:**
- Reinicia la terminal después de instalar
- Verifica que Git esté en el PATH: `echo %PATH%`
- Reinstala Git y asegúrate de seleccionar "Add Git to PATH"

**Linux/macOS:**
- Verifica que Git esté instalado: `which git`
- Si no está, reinstala usando los métodos anteriores

### Error de permisos

**Linux/macOS:**
```bash
# Dar permisos de ejecución si es necesario
chmod +x /usr/local/bin/git
```

### Actualizar Git

**Windows:**
- Descarga e instala la nueva versión desde git-scm.com

**Linux:**
```bash
# Ubuntu/Debian
sudo apt update && sudo apt upgrade git

# Fedora
sudo dnf update git
```

**macOS (Homebrew):**
```bash
brew upgrade git
```

---

## Recursos Adicionales

- **Documentación oficial**: https://git-scm.com/doc
- **GitHub Guides**: https://guides.github.com
- **Pro Git Book**: https://git-scm.com/book (libro gratuito y completo)
- **Git Cheat Sheet**: Ver `comandos_git.md` en esta carpeta

---

## Notas Importantes

- **Windows**: Git Bash es la mejor opción para una experiencia similar a Linux/macOS
- **Linux**: La versión de Git en los repositorios puede no ser la más reciente
- **macOS**: Xcode Command Line Tools es la forma más simple y viene con otras herramientas útiles
- **Todos**: Configura tu identidad antes de hacer commits para que aparezcan correctamente en el historial
