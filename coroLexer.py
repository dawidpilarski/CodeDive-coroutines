from pygments.lexers import CppLexer
from pygments.token import Name, Keyword

class CustomLexer(CppLexer):
	name="CppCoro"
	aliases="cpp-coro"

	coro_keywords=['co_await', 'co_return', 'co_yield']

	def get_tokens_unprocessed(self, text):
		for index, token, value in CppLexer.get_tokens_unprocessed(self, text):
			if value in self.coro_keywords:
				yield index, Keyword, value
			elif token is Name.Function:
				yield index, Name, value
			else:
				yield index, token, value