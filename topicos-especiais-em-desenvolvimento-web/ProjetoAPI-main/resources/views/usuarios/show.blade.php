@extends('layouts.app')

@section('content')
<h1>Detalhes do Usuário</h1>
<p>Nome: {{ $usuario['nome'] }}</p>
<p>Data de Nascimento: {{ $usuario['dataNascimento'] }}</p>
<p>Email: {{ $usuario['email'] }}</p>
<p>CPF: {{ $usuario['cpf'] }}</p>
<p>Telefone: {{ $usuario['fone'] }}</p>
<p>Endereço: {{ $usuario['endereco_rua'] }}, {{ $usuario['endereco_numero'] }}, {{ $usuario['endereco_bairro'] }}, {{ $usuario['endereco_cidade'] }}, {{ $usuario['endereco_estado'] }}</p>
<a href="{{ route('usuarios.edit', $usuario['id']) }}">Editar</a>
<form action="{{ route('usuarios.destroy', $usuario['id']) }}" method="POST">
  @csrf
  @method('DELETE')
  <button type="submit">Deletar</button>
</form>
@endsection