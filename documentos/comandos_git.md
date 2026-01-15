# Comandos Git útiles

## Configuración inicial

### `git config`
**Descripción:** Configura el nombre de usuario y email para los commits.

**Ejemplo:**
```bash
git config --global user.name "Tu Nombre"
git config --global user.email "tu.email@ejemplo.com"
```

### `git init`
**Descripción:** Inicializa un nuevo repositorio Git en el directorio actual.

**Ejemplo:**
```bash
git init
```

---

## Trabajo con repositorios remotos

### `git clone`
**Descripción:** Clona un repositorio remoto a tu máquina local.

**Ejemplo:**
```bash
git clone https://github.com/usuario/repositorio.git
git clone https://github.com/usuario/repositorio.git mi-carpeta
```

### `git remote`
**Descripción:** Gestiona las conexiones con repositorios remotos.

**Ejemplo:**
```bash
git remote add origin https://github.com/usuario/repositorio.git
git remote -v  # Lista los remotos configurados
git remote remove origin  # Elimina un remoto
```

### `git push`
**Descripción:** Envía los commits locales al repositorio remoto.

**Ejemplo:**
```bash
git push origin main
git push -u origin main  # Establece el upstream en el primer push
git push --force  # Fuerza el push (usar con precaución)
```

### `git pull`
**Descripción:** Descarga y fusiona cambios del repositorio remoto.

**Ejemplo:**
```bash
git pull origin main
git pull  # Si ya tienes upstream configurado
```

### `git fetch`
**Descripción:** Descarga cambios del remoto sin fusionarlos automáticamente.

**Ejemplo:**
```bash
git fetch origin
git fetch --all  # Descarga de todos los remotos
```

---

## Estado y cambios

### `git status`
**Descripción:** Muestra el estado del directorio de trabajo y el área de staging.

**Ejemplo:**
```bash
git status
git status -s  # Versión corta
```

### `git diff`
**Descripción:** Muestra las diferencias entre archivos modificados.

**Ejemplo:**
```bash
git diff  # Cambios no staged
git diff --staged  # Cambios en staging
git diff HEAD  # Todos los cambios
git diff commit1 commit2  # Compara dos commits
```

### `git log`
**Descripción:** Muestra el historial de commits.

**Ejemplo:**
```bash
git log
git log --oneline  # Versión compacta
git log --graph --oneline --all  # Con gráfico de ramas
git log -5  # Últimos 5 commits
git log --author="Nombre"  # Commits de un autor
```

---

## Agregar y confirmar cambios

### `git add`
**Descripción:** Agrega archivos al área de staging.

**Ejemplo:**
```bash
git add archivo.txt  # Agrega un archivo específico
git add .  # Agrega todos los archivos modificados
git add *.cpp  # Agrega todos los archivos .cpp
git add -A  # Agrega todos los cambios (incluyendo eliminados)
```

### `git commit`
**Descripción:** Guarda los cambios en el historial del repositorio.

**Ejemplo:**
```bash
git commit -m "Mensaje del commit"
git commit -am "Mensaje"  # Agrega y commitea en un solo paso
git commit --amend  # Modifica el último commit
```

### `git reset`
**Descripción:** Deshace cambios en el staging o commits.

**Ejemplo:**
```bash
git reset HEAD archivo.txt  # Quita del staging
git reset --soft HEAD~1  # Deshace el último commit, mantiene cambios
git reset --hard HEAD~1  # Deshace el último commit, elimina cambios (¡cuidado!)
```

---

## Ramas (branches)

### `git branch`
**Descripción:** Lista, crea o elimina ramas.

**Ejemplo:**
```bash
git branch  # Lista ramas locales
git branch -a  # Lista todas las ramas (locales y remotas)
git branch nueva-rama  # Crea una nueva rama
git branch -d nombre-rama  # Elimina una rama
git branch -D nombre-rama  # Fuerza la eliminación
```

### `git checkout`
**Descripción:** Cambia de rama o restaura archivos.

**Ejemplo:**
```bash
git checkout nombre-rama  # Cambia a otra rama
git checkout -b nueva-rama  # Crea y cambia a nueva rama
git checkout -- archivo.txt  # Restaura un archivo modificado
```

### `git switch`
**Descripción:** Cambia de rama (comando más moderno y específico).

**Ejemplo:**
```bash
git switch nombre-rama
git switch -c nueva-rama  # Crea y cambia a nueva rama
```

### `git merge`
**Descripción:** Fusiona una rama con la rama actual.

**Ejemplo:**
```bash
git merge nombre-rama  # Fusiona nombre-rama en la rama actual
git merge --no-ff nombre-rama  # Crea un merge commit explícito
```

---

## Guardar cambios temporalmente

### `git stash`
**Descripción:** Guarda temporalmente cambios sin hacer commit.

**Ejemplo:**
```bash
git stash  # Guarda cambios temporalmente
git stash save "mensaje"  # Guarda con mensaje
git stash list  # Lista los stashes
git stash pop  # Aplica y elimina el último stash
git stash apply  # Aplica el stash pero lo mantiene
git stash drop  # Elimina un stash
```

---

## Deshacer cambios

### `git restore`
**Descripción:** Restaura archivos del working directory o staging.

**Ejemplo:**
```bash
git restore archivo.txt  # Restaura archivo modificado
git restore --staged archivo.txt  # Quita del staging
```

### `git revert`
**Descripción:** Crea un nuevo commit que deshace cambios de un commit anterior.

**Ejemplo:**
```bash
git revert HEAD  # Revierte el último commit
git revert commit-hash  # Revierte un commit específico
```

---

## Información y búsqueda

### `git show`
**Descripción:** Muestra información sobre un commit específico.

**Ejemplo:**
```bash
git show  # Último commit
git show commit-hash  # Commit específico
git show HEAD~1  # Commit anterior
```

### `git grep`
**Descripción:** Busca texto en el repositorio.

**Ejemplo:**
```bash
git grep "texto"  # Busca en todos los archivos
git grep -n "texto"  # Muestra números de línea
```

### `git blame`
**Descripción:** Muestra quién y cuándo modificó cada línea de un archivo.

**Ejemplo:**
```bash
git blame archivo.txt
```

---

## Etiquetas (tags)

### `git tag`
**Descripción:** Crea, lista o elimina etiquetas.

**Ejemplo:**
```bash
git tag  # Lista etiquetas
git tag v1.0.0  # Crea una etiqueta ligera
git tag -a v1.0.0 -m "Versión 1.0.0"  # Crea etiqueta anotada
git tag -d v1.0.0  # Elimina etiqueta local
git push origin v1.0.0  # Envía etiqueta al remoto
git push --tags  # Envía todas las etiquetas
```

---

## Limpieza

### `git clean`
**Descripción:** Elimina archivos no rastreados del directorio de trabajo.

**Ejemplo:**
```bash
git clean -n  # Vista previa (dry-run)
git clean -f  # Elimina archivos no rastreados
git clean -fd  # Elimina archivos y directorios
git clean -i  # Modo interactivo
```

---

## Alias útiles

### `git config --global alias`
**Descripción:** Crea atajos para comandos frecuentes.

**Ejemplo:**
```bash
git config --global alias.st status
git config --global alias.co checkout
git config --global alias.br branch
git config --global alias.ci commit
git config --global alias.unstage 'reset HEAD --'
git config --global alias.last 'log -1 HEAD'
```

---

## Comandos combinados útiles

### Ver cambios antes de commitear
```bash
git diff --staged
```

### Ver historial con gráfico
```bash
git log --oneline --graph --decorate --all
```

### Actualizar rama local con remoto
```bash
git fetch origin
git merge origin/main
# O simplemente:
git pull origin main
```

### Ver qué archivos cambió un commit
```bash
git show --name-only commit-hash
```

### Cambiar mensaje del último commit
```bash
git commit --amend -m "Nuevo mensaje"
```