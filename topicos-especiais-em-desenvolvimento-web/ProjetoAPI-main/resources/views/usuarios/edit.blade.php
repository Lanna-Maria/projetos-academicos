@extends('layouts.app')

@section('content')
<h1>Editar Usuário</h1>
<form action="{{ route('usuarios.update', $usuario['id']) }}" method="POST">
  @csrf
  @method('PUT')
  <label for="nome">Nome:</label>
  <input type="text" name="nome" id="nome" value="{{ $usuario['nome'] }}" required>

  <label for="dataNascimento">Data de Nascimento:</label>
  <input type="date" name="dataNascimento" id="dataNascimento" value="{{ $usuario['dataNascimento'] }}" required>

  <label for="email">Email:</label>
  <input type="email" name="email" id="email" value="{{ $usuario['email'] }}" required>

  <label for="cpf">CPF:</label>
  <input type="text" name="cpf" id="cpf" value="{{ $usuario['cpf'] }}" required>

  <label for="fone">Telefone:</label>
  <input type="text" name="fone" id="fone" value="{{ $usuario['fone'] }}" required>

  <label for="endereco_rua">Rua:</label>
  <input type="text" name="endereco_rua" id="endereco_rua" value="{{ $usuario['endereco_rua'] }}" required>

  <label for="endereco_cep">CEP:</label>
  <input type="text" name="endereco_cep" id="endereco_cep" value="{{ $usuario['endereco_cep'] }}" required>

  <label for="endereco_bairro">Bairro:</label>
  <input type="text" name="endereco_bairro" id="endereco_bairro" value="{{ $usuario['endereco_bairro'] }}" required>

  <label for="endereco_numero">Número:</label>
  <input type="text" name="endereco_numero" id="endereco_numero" value="{{ $usuario['endereco_numero'] }}" required>

  <label for="endereco_cidade">Cidade:</label>
  <input type="text" name="endereco_cidade" id="endereco_cidade" value="{{ $usuario['endereco_cidade'] }}" required>

  <label for="endereco_estado">Estado:</label>
  <input type="text" name="endereco_estado