class User:
    def __init__(self, name, email, password):
        self.name = name
        self.email = email
        self.password = password
    
    @classmethod
    def from_string(cls, string_params):
        # 코드를 쓰세요
        params_list=string_params.split(",")
        name=cls.params_list[0]
        email=cls.params_list[1]
        passwd=cls.params_list[2]

        return cls(name,email,passwd)
    
    @classmethod
    def from_list(cls, list_params):
        # 코드를 쓰세요
        name=cls.list_params[0]
        email=cls.list_params[1]
        passwd=cls.list_params[2]

        return cls(name,email,passwd)

# 유저 생성 및 초기값 설정
younghoon = User.from_string("강영훈,younghoon@codeit.kr,123456")
yoonsoo = User.from_list(["이윤수", "yoonsoo@codeit.kr", "abcdef"])

print(younghoon.name, younghoon.email, younghoon.password)
print(yoonsoo.name, yoonsoo.email, yoonsoo.password)