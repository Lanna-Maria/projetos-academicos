<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

return new class extends Migration
{
    /**
     * Run the migrations.
     */
    public function up()
    {
        Schema::create('usuarios', function (Blueprint $table) {
            $table->id();
            $table->string('nome');
            $table->date('dataNascimento');
            $table->string('email')->unique();
            $table->string('cpf')->unique();
            $table->string('fone');
            $table->string('endereco_rua');
            $table->string('endereco_cep');
            $table->string('endereco_bairro');
            $table->string('endereco_numero');
            $table->string('endereco_cidade');
            $table->string('endereco_estado');
            $table->timestamps();
        });
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        Schema::dropIfExists('usuarios');
    }
};
