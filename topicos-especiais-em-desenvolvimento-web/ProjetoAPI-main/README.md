<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>CRUD de Usuário com Laravel e Guzzle</title>
</head>
<body>

<h1>CRUD de Usuário com Laravel e Guzzle 🚀</h1>

<p>Este projeto implementa um CRUD (Create, Read, Update, Delete) para gerenciamento de usuários, utilizando o <strong>Laravel</strong> e a biblioteca <strong>Guzzle</strong>. O sistema salva, lista, atualiza e deleta os dados de usuários em um banco de dados local, utilizando o <strong>JSON Server API</strong> como serviço para simulação de uma API RESTful. Este trabalho é parte da disciplina de <strong>Tópicos Especiais em Desenvolvimento Web</strong>.</p>

<h2>Funcionalidades 📝</h2>
<ul>
    <li><strong>Nome</strong> 👤</li>
    <li><strong>Data de Nascimento</strong> 🎂</li>
    <li><strong>Email</strong> 📧</li>
    <li><strong>CPF</strong> 🆔</li>
    <li><strong>Telefone</strong> 📞</li>
    <li><strong>Endereço</strong> 🏠 (inclui os campos: rua, cep, bairro, número, cidade, estado)</li>
</ul>

<p>O sistema permite as seguintes operações:</p>
<ul>
    <li><strong>Criar</strong> ➕: Adicionar um novo usuário.</li>
    <li><strong>Listar</strong> 📜: Visualizar todos os usuários cadastrados.</li>
    <li><strong>Atualizar</strong> ✏️: Alterar as informações de um usuário existente.</li>
    <li><strong>Deletar</strong> 🗑️: Remover um usuário do banco de dados.</li>
</ul>

<h2>Tecnologias Utilizadas ⚙️</h2>
<ul>
    <li><strong>Laravel</strong>: Framework PHP para desenvolvimento de aplicações web.</li>
    <li><strong>Guzzle</strong>: Biblioteca PHP para fazer requisições HTTP (utilizada para comunicar com o JSON Server).</li>
    <li><strong>JSON Server API</strong>: Serviço que simula uma API RESTful para salvar os dados localmente.</li>
</ul>

<h2>Requisitos 🛠️</h2>
<ul>
    <li><strong>PHP</strong> 8.x ou superior</li>
    <li><strong>Laravel</strong> 8.x ou superior</li>
    <li><strong>Node.js</strong> (para rodar o JSON Server)</li>
</ul>

<h2>Instalação ⚡</h2>

<h3>1. Clonar o Repositório</h3>
<p>Clone este repositório para sua máquina local:</p>
<pre><code>git clone https://github.com/Lanna-Maria/ProjetoAPI.git
cd ProjetoAPI</code></pre>

<h3>2. Instalar Dependências do Laravel</h3>
<p>Instale as dependências do Laravel utilizando o Composer:</p>
<pre><code>composer install</code></pre>

<h3>3. Instalar JSON Server</h3>
<p>Instale o JSON Server globalmente utilizando o npm:</p>
<pre><code>npm install -g json-server</code></pre>

<h3>4. Configurar o JSON Server</h3>
<p>Crie um arquivo <code>db.json</code> na raiz do projeto com a estrutura inicial dos dados (exemplo):</p>
<pre><code>{
  "usuarios": []
}</code></pre>

<p>Em seguida, inicie o JSON Server para simular a API RESTful:</p>
<pre><code>json-server --watch db.json --port 3000</code></pre>

<h3>5. Configurar o Laravel</h3>
<p>Copie o arquivo <code>.env.example</code> para <code>.env</code> e configure a conexão com o banco de dados de sua escolha (se necessário). Não é necessário configurar banco de dados se o JSON Server for utilizado como serviço.</p>

<h3>6. Instalar Guzzle</h3>
<p>Instale a biblioteca Guzzle para realizar as requisições HTTP:</p>
<pre><code>composer require guzzlehttp/guzzle</code></pre>

<h3>7. Rodar as Migrações (Se necessário)</h3>
<p>Caso você opte por usar um banco de dados real, rode as migrações:</p>
<pre><code>php artisan migrate</code></pre>

<h3>8. Iniciar o Servidor do Laravel</h3>
<p>Inicie o servidor de desenvolvimento do Laravel:</p>
<pre><code>php artisan serve</code></pre>
<p>Agora, a aplicação estará rodando em <code>http://localhost:8000</code>.</p>

<h2>Testando a Aplicação 🧪</h2>

<p>Com o Laravel rodando em <code>http://localhost:8000</code> e o JSON Server simulando a API em <code>http://localhost:3000</code>, você pode testar o CRUD via Postman ou navegador. As rotas disponíveis para o CRUD são:</p>
<ul>
    <li><strong>POST</strong> /usuarios ➕ - Criar um novo usuário.</li>
    <li><strong>GET</strong> /usuarios 📜 - Listar todos os usuários.</li>
    <li><strong>PUT</strong> /usuarios/{id} ✏️ - Atualizar um usuário existente.</li>
    <li><strong>DELETE</strong> /usuarios/{id} 🗑️ - Deletar um usuário.</li>
</ul>


</body>
</html>
