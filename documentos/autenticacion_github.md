# Autenticación con GitHub

Esta guía te ayudará a configurar la autenticación con GitHub usando diferentes métodos.

---

## Método 1: Personal Access Token (HTTPS) - Recomendado

GitHub ya no acepta contraseñas para autenticación HTTPS. Debes usar un Personal Access Token (PAT).

### Paso 1: Crear un Personal Access Token

1. **Ir a GitHub:**
   - Ve a: https://github.com/settings/tokens
   - O: GitHub → Tu perfil → Settings → Developer settings → Personal access tokens → Tokens (classic)

2. **Generar nuevo token:**
   - Haz clic en "Generate new token" → "Generate new token (classic)"
   - Dale un nombre descriptivo (ej: "Mi Laptop - Desarrollo")
   - Selecciona la expiración (30, 60, 90 días, o sin expiración)
   - Selecciona los permisos (scopes) necesarios:
     - ✅ `repo` - Acceso completo a repositorios privados
     - ✅ `workflow` - Si usas GitHub Actions
     - ✅ `write:packages` - Si subes paquetes
     - ✅ `delete:packages` - Si eliminas paquetes

3. **Generar y copiar:**
   - Haz clic en "Generate token"
   - **¡IMPORTANTE!** Copia el token inmediatamente (solo se muestra una vez)
   - Guárdalo en un lugar seguro

### Paso 2: Usar el token

#### Opción A: Git te pedirá credenciales automáticamente

```bash
# Al hacer push/pull, Git pedirá:
# Username: tu-usuario-github
# Password: pega-tu-token-aqui (NO tu contraseña)
git push origin main
```

#### Opción B: Guardar credenciales en el sistema

**Windows:**
```bash
# Configurar Git Credential Manager
git config --global credential.helper manager-core

# O usar el almacenamiento de Windows
git config --global credential.helper wincred
```

**macOS:**
```bash
# Usar Keychain de macOS
git config --global credential.helper osxkeychain
```

**Linux:**
```bash
# Usar libsecret
git config --global credential.helper libsecret

# O almacenar en archivo (menos seguro)
git config --global credential.helper store
```

#### Opción C: Incluir token en la URL (temporal, no recomendado)

```bash
# Solo para pruebas rápidas
git remote set-url origin https://TU_TOKEN@github.com/usuario/repo.git

# O clonar directamente
git clone https://TU_TOKEN@github.com/usuario/repo.git
```

### Paso 3: Verificar autenticación

```bash
# Probar con un push o pull
git push origin main

# O verificar remotamente
git ls-remote origin
```

---

## Método 2: SSH Keys (Recomendado para uso frecuente)

Las SSH keys son más seguras y convenientes para uso diario.

### Paso 1: Generar una clave SSH

```bash
# Generar nueva clave SSH (reemplaza con tu email)
ssh-keygen -t ed25519 -C "tu.email@ejemplo.com"

# Si tu sistema no soporta ed25519, usa RSA:
ssh-keygen -t rsa -b 4096 -C "tu.email@ejemplo.com"

# Presiona Enter para aceptar la ubicación por defecto
# Opcional: Ingresa una contraseña para mayor seguridad
```

### Paso 2: Agregar la clave SSH al ssh-agent

**macOS/Linux:**
```bash
# Iniciar el agente SSH
eval "$(ssh-agent -s)"

# Agregar la clave
ssh-add ~/.ssh/id_ed25519
# O si usaste RSA:
ssh-add ~/.ssh/id_rsa
```

**Windows (Git Bash):**
```bash
# Iniciar el agente SSH
eval "$(ssh-agent -s)"

# Agregar la clave
ssh-add ~/.ssh/id_ed25519
```

**Windows (PowerShell):**
```powershell
# Iniciar el servicio ssh-agent
Start-Service ssh-agent

# Agregar la clave
ssh-add ~/.ssh/id_ed25519
```

### Paso 3: Copiar la clave pública

**macOS:**
```bash
# Copiar al portapapeles
pbcopy < ~/.ssh/id_ed25519.pub
```

**Linux:**
```bash
# Mostrar la clave
cat ~/.ssh/id_ed25519.pub

# O copiar al portapapeles (si tienes xclip)
xclip -sel clip < ~/.ssh/id_ed25519.pub
```

**Windows (Git Bash):**
```bash
# Mostrar la clave
cat ~/.ssh/id_ed25519.pub

# O copiar (si tienes clip.exe)
cat ~/.ssh/id_ed25519.pub | clip
```

**Windows (PowerShell):**
```powershell
# Mostrar la clave
Get-Content ~/.ssh/id_ed25519.pub

# O copiar al portapapeles
Get-Content ~/.ssh/id_ed25519.pub | Set-Clipboard
```

### Paso 4: Agregar la clave a GitHub

1. **Ir a GitHub:**
   - Ve a: https://github.com/settings/keys
   - O: GitHub → Tu perfil → Settings → SSH and GPG keys

2. **Agregar nueva clave:**
   - Haz clic en "New SSH key"
   - Título: Un nombre descriptivo (ej: "Mi Laptop")
   - Key: Pega la clave pública que copiaste
   - Haz clic en "Add SSH key"

### Paso 5: Configurar Git para usar SSH

```bash
# Si ya tienes un repo con HTTPS, cambiar a SSH
git remote set-url origin git@github.com:usuario/repo.git

# O clonar usando SSH desde el inicio
git clone git@github.com:usuario/repo.git
```

### Paso 6: Probar la conexión SSH

```bash
# Probar conexión
ssh -T git@github.com

# Deberías ver:
# Hi usuario! You've successfully authenticated, but GitHub does not provide shell access.
```

---

## Método 3: GitHub CLI (gh)

GitHub CLI es una herramienta de línea de comandos oficial de GitHub.

### Instalar GitHub CLI

**macOS:**
```bash
brew install gh
```

**Windows (winget):**
```powershell
winget install --id GitHub.cli
```

**Windows (Chocolatey):**
```powershell
choco install gh
```

**Linux (Ubuntu/Debian):**
```bash
curl -fsSL https://cli.github.com/packages/githubcli-archive-keyring.gpg | sudo dd of=/usr/share/keyrings/githubcli-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/githubcli-archive-keyring.gpg] https://cli.github.com/packages stable main" | sudo tee /etc/apt/sources.list.d/github-cli.list > /dev/null
sudo apt update
sudo apt install gh
```

### Autenticarse con GitHub CLI

```bash
# Iniciar sesión
gh auth login

# Seguir las instrucciones:
# 1. Seleccionar GitHub.com
# 2. Seleccionar HTTPS o SSH
# 3. Autenticar vía navegador o token
```

### Usar GitHub CLI con Git

```bash
# Clonar un repo
gh repo clone usuario/repo

# Crear un nuevo repo
gh repo create mi-repo --public

# Ver repositorios
gh repo list
```

---

## Método 4: Credential Manager (Windows)

Windows tiene un administrador de credenciales integrado.

### Configurar

```bash
# Configurar Git para usar Windows Credential Manager
git config --global credential.helper manager-core

# O la versión anterior
git config --global credential.helper wincred
```

### Usar

1. La primera vez que hagas `git push` o `git pull`, Windows te pedirá credenciales
2. Ingresa:
   - **Usuario**: tu-usuario-github
   - **Contraseña**: tu-personal-access-token (NO tu contraseña de GitHub)
3. Windows guardará las credenciales automáticamente

### Ver/Editar credenciales guardadas

**Windows:**
- Ve a: Panel de Control → Credenciales de Windows → Credenciales genéricas
- Busca: `git:https://github.com`
- Puedes ver o editar las credenciales guardadas

---

## Verificar tu autenticación

### Probar con HTTPS

```bash
# Verificar remotamente
git ls-remote https://github.com/usuario/repo.git

# O hacer un push/pull
git push origin main
```

### Probar con SSH

```bash
# Probar conexión SSH
ssh -T git@github.com

# Verificar remotamente
git ls-remote git@github.com:usuario/repo.git
```

### Ver configuración actual

```bash
# Ver URLs de los remotos
git remote -v

# Ver configuración de credenciales
git config --list | grep credential
```

---

## Solución de Problemas

### Error: "Authentication failed"

**HTTPS:**
- Verifica que estés usando un Personal Access Token, no tu contraseña
- Asegúrate de que el token tenga los permisos necesarios (`repo`)
- Verifica que el token no haya expirado

**SSH:**
- Verifica que la clave esté agregada a GitHub
- Prueba la conexión: `ssh -T git@github.com`
- Verifica que el ssh-agent esté corriendo y tenga la clave

### Error: "Permission denied (publickey)"

```bash
# Verificar que la clave esté en el agente
ssh-add -l

# Si no aparece, agregarla
ssh-add ~/.ssh/id_ed25519

# Verificar que GitHub tenga la clave pública
ssh -T git@github.com
```

### Cambiar de HTTPS a SSH

```bash
# Ver URL actual
git remote -v

# Cambiar a SSH
git remote set-url origin git@github.com:usuario/repo.git

# Verificar
git remote -v
```

### Cambiar de SSH a HTTPS

```bash
# Cambiar a HTTPS
git remote set-url origin https://github.com/usuario/repo.git

# Verificar
git remote -v
```

### Limpiar credenciales guardadas

**Windows:**
```powershell
# Eliminar credenciales de Windows
cmdkey /list
cmdkey /delete:git:https://github.com
```

**macOS:**
```bash
# Eliminar del Keychain
git credential-osxkeychain erase
host=github.com
protocol=https
# Presiona Enter dos veces
```

**Linux:**
```bash
# Si usas store, eliminar el archivo
rm ~/.git-credentials
```

---

## Recomendaciones de Seguridad

1. **Usa SSH para desarrollo diario** - Más seguro y conveniente
2. **Usa Personal Access Tokens con expiración** - No uses tokens sin expiración
3. **Dale permisos mínimos necesarios** - Solo los scopes que realmente necesitas
4. **No compartas tus tokens o claves privadas** - Nunca las subas a repositorios
5. **Usa diferentes tokens para diferentes propósitos** - Un token para desarrollo, otro para CI/CD
6. **Revisa tus tokens regularmente** - Elimina los que ya no uses
7. **Usa contraseñas en tus claves SSH** - Añade una capa extra de seguridad

---

## Recursos Adicionales

- **Documentación oficial de GitHub**: https://docs.github.com/en/authentication
- **Generar Personal Access Token**: https://github.com/settings/tokens
- **SSH Keys en GitHub**: https://github.com/settings/keys
- **GitHub CLI**: https://cli.github.com/
